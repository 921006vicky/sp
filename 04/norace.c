#include <stdio.h>
#include <pthread.h>

#define LOOPS 100000000
int money = 1000;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *inc()
{
    for (int i = 0; i < LOOPS; i++) {
        pthread_mutex_lock(&mutex);
        money = money + 1;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *dec()
{
    for (int i = 0; i < LOOPS; i++) {
        pthread_mutex_lock(&mutex);
        money = money - 1;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, inc, NULL);
    pthread_create(&thread2, NULL, dec, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("money=%d\n", money);

    return 0;
}
