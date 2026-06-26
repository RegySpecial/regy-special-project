template<typename keyDataType,typename valueDataType,const typename rowsDataType>
class hashTable{
public:
    keyDataType key;
    valueDataType value;
    table*next;
    unsigned long long size;
    unsigned long long capacity;
    static unsigned long long hash(keyDataType key){
        unsigned long long hash=0;
        for(unsigned long long i=0;key+i!=0;i++)hash+=31*(*(key+i))%this->capacity
        return hash;
    }
    inline valueDataType operator[](keyDataType key){
        return*(this+hashTable::hash(key));
    }
    void add(keyDataType key,valueDataType value){
        
    }
};