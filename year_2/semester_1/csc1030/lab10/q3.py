# Questions 2 and 3
def basic_hash(str):

    hash_code = 0

    for i in str:
        hash_code += ord(i)

    return hash_code

def position_hash(str):

    hash_code = 0

    prime = 13
    for i in range(len(str)):
        hash_code += (ord(str[i]) * (prime**i))

    return hash_code

def insert(str, buckets):

    index = basic_hash(str) % len(buckets)

    buckets[index].append(str)

def insert_position_hash(str, buckets):

    index = position_hash(str) % len(buckets)

    buckets[index].append(str)

if __name__ == '__main__':

    # mimic a bucket array using the following:
    buckets = [[] for _ in range(10)]

    insert('stop', buckets)
    insert('tops', buckets)
    insert('pots', buckets)
    insert('spot', buckets)

    print(buckets)

    buckets = [[] for _ in range(11)]

    insert_position_hash('stop', buckets)
    insert_position_hash('tops', buckets)
    insert_position_hash('pots', buckets)
    insert_position_hash('spot', buckets)

    print(buckets)
