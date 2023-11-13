#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 380. Insert Delete GetRandom O(1)

typedef struct {
    int* idx;
    int* value;
    int size;
    int capa;
} RandomizedSet;

RandomizedSet* randomizedSetCreate() {
    RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    obj->value = (int*)malloc(sizeof(int) * 1000);
    obj->size = 0;
    obj->capa = 1000;
    return obj;
    
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    if (obj == NULL){
        return false;
    }

    for (int i=0; i<obj->size; i++){
        if (obj->value[i] == val){
            return false;
        }
    }

    if (obj->size >= obj->capa){
        obj->capa *= 2;
        obj->value = (int*)realloc(obj->value, sizeof(int) * obj->capa);
    }

    obj->value[obj->size] = val;
    obj->size++;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    if (obj == NULL){
        return false;
    }
    
    for (int i=0; i<obj->size; i++){
        if (obj->value[i] == val){
            obj->value[i] = obj->value[obj->size-1];
            obj->size--;
            return true;
        }
    }

    return false;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int randIdx = rand() % obj->size;
    int randEle = obj->value[randIdx];
    return randEle;
}

void randomizedSetFree(RandomizedSet* obj) {
    if (obj!=NULL){
        free(obj->value);
        free(obj);
    }
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);
 
 * bool param_2 = randomizedSetRemove(obj, val);
 
 * int param_3 = randomizedSetGetRandom(obj);
 
 * randomizedSetFree(obj);
*/

// Driver code
int main(void) {
    RandomizedSet* obj = randomizedSetCreate();
    bool param_1 = randomizedSetInsert(obj, 1);
    bool param_2 = randomizedSetRemove(obj, 2);
    bool param_3 = randomizedSetInsert(obj, 2);
    int param_4 = randomizedSetGetRandom(obj);
    bool param_5 = randomizedSetRemove(obj, 1);
    bool param_6 = randomizedSetInsert(obj, 2);
    int param_7 = randomizedSetGetRandom(obj);
    randomizedSetFree(obj);

    printf("param_1: %d\n", param_1); // 1
    printf("param_2: %d\n", param_2); // 0
    printf("param_3: %d\n", param_3); // 1
    printf("param_4: %d\n", param_4); // 1
    printf("param_5: %d\n", param_5); // 1
    printf("param_6: %d\n", param_6); // 0
    printf("param_7: %d\n", param_7); // 2

    return 0;
}
