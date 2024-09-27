# Time log

- 15:42:20 Hashtable Iterator 实现完成（Next 函数尤其重要，因为在遍历完上一个 LinkedList 后需要检查下一个，而不是直接退出）。修复了 Insert 的时候空间未释放的问题。

# Minor-tasks

## study

- [x] 链表作业完成
- [x] Hashtable 作业完成

## life

- [x] 洗脸刷牙
- [x] 喝碗温开水
- [x] 涂眼霜
- [x] 喷米诺地尔
- [x] 卷刘海
- [x] 涂生长因子
- [x] 泡茶（喝水 3L）

# Summary

```C
// The hash table implementation.
//
// A hash table is an array of buckets, where each bucket is a linked list
// of HTKeyValue structs.
typedef struct ht {
  int             num_buckets;   // # of buckets in this HT?
  int             num_elements;  // # of elements currently in this HT?
  LinkedList    **buckets;       // the array of buckets
} HashTable;

// The hash table iterator.
typedef struct ht_it {
  HashTable  *ht;          // the HT we're pointing into
  int         bucket_idx;  // which bucket are we in?
  LLIterator *bucket_it;   // iterator for the bucket, or NULL
} HTIterator;

bool HTIterator_IsValid(HTIterator *iter) {
  // STEP 4: implement HTIterator_IsValid.
  return iter != NULL && iter->ht != NULL && iter->bucket_it != NULL && LLIterator_IsValid(iter->bucket_it);
}

bool HTIterator_Next(HTIterator *iter) {
  // STEP 5: implement HTIterator_Next.
  if(HTIterator_IsValid(iter)) {
    bool valid = LLIterator_Next(iter->bucket_it);
    if(!valid) {
        // detects the first bucket that is no empty
        HashTable* ht = iter->ht;
        int bucket_num = ht->num_buckets;
        LinkedList** buckets = ht->buckets;

        int next_bucket_id = iter->bucket_idx + 1;

        while(next_bucket_id < bucket_num && LinkedList_NumElements(buckets[next_bucket_id]) == 0) {
            next_bucket_id += 1;
        }
        if(next_bucket_id < bucket_num) {
            LLIterator_Free(iter->bucket_it);
            iter->bucket_idx = next_bucket_id;
            iter->bucket_it = LLIterator_Allocate(ht->buckets[iter->bucket_idx]);
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return true;
    }
  }
  else {
    return false;
  }
}

bool HTIterator_Get(HTIterator *iter, HTKeyValue_t *keyvalue) {
  // STEP 6: implement HTIterator_Get.
    if(!HTIterator_IsValid(iter)) {
        return false;
    }
    HTKeyValue_t* payload;
  LLIterator_Get(iter->bucket_it, &payload);  // you may need to change this return value
    keyvalue->key = payload->key;
    keyvalue->value = payload->value;
    return keyvalue != NULL;
}
```
