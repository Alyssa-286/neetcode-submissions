class LRUCache {
private:
struct node
    {
        int key,val;
        node* prev;
        node* next;
        node(int k,int v):
        key(k),
        val(v),
        prev(nullptr),
        next(nullptr){}
    };
int cap;
 node* head_dummy;
    node* tail_dummy;
    unordered_map<int,node*>cache;
public:
    
   
    LRUCache(int capacity) {
        cap=capacity;
        head_dummy=new node(0,0);
        tail_dummy=new node(0,0);
        head_dummy->next=tail_dummy;
        tail_dummy->prev=head_dummy;

        
    }
    void remove(node* target)
    {
        /*
        if(target->head==nullptr)//no nodes
        return;
        else if(head->next==nullptr)//single node
        free(head->val);
        else
        {
            node *temp=head;
            while(temp!=nullptr && temp==target)
            {
                temp=temp->next;
            }
            if(temp)//target found
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free (temp);
            }
        }
        // else target not found or not present???
        */
        //we dont have to do all theseee since we are using dummy all nodes are gaurenteed to have a real node
        //soooo
         target->prev->next=target->next;
         target->next->prev=target->prev;
    }
    void insert_at_head(node* target)
    {
        node* first_real_node=head_dummy->next;
        head_dummy->next=target;
        target->next=first_real_node;
        first_real_node->prev=target;
        target->prev=head_dummy;
    }
    int get(int key) {
        if(cache.find(key)==cache.end())
        return -1;
        else
        {
            node* target=cache[key];
            remove(target);
            insert_at_head(target);
            return target->val;
        }
        
    }
    
    void put(int key, int value) {
        if(cache.count(key))
        {
             node* target=cache[key];
             target->val=value;
             remove(target);
            insert_at_head(target);
        }
        else
        {
            if(cache.size()==cap)
           { node* lru=tail_dummy->prev;
            remove(lru);
            cache.erase(lru->key);
            delete(lru);
           }
           node* newnode=new node(key,value);
           cache[key]=newnode;
           insert_at_head(newnode);
        }
        
    }
};
