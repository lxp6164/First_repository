//试着自己撸一个专用的stack
//底层用链表实现

#define max(a,b) a>b?a:b

typedef struct _node
{
    int data;
    struct _node* next;
}Node;

typedef struct _stack
{
    Node *head;  //栈顶
    Node *tail;  //栈底
}Stack;

void init_stack(Stack* stack)
{
    stack->head = NULL;
    stack->tail = NULL;
}
//addhead
void push(Stack* stack,int value)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value; //事实上这道题连data都不要...
    if(stack->head==NULL){
        stack->tail = node;
        node->next = NULL;
    }else
       node->next = stack->head;
       
    stack->head = node;
}

//deletehead
void pop(Stack* stack)
{
    Node* node = stack->head;
    //自己保证不出现...
    //其实也可以用　if(node==NULL) return NULL;来判断栈是否为空 
    if(node==stack->tail){
        stack->head = stack->tail = NULL;
        free(node);
    }else{
        stack->head = stack->head->next;
        free(node);
    }
}

int top(Stack* stack)
{
    //保证不为空时才调用top
    Node* node = stack->head;
    return node->data;
}

int empty(Stack* stack)
{
    Node* node = stack->head;
    if(node==NULL) return 1; //1为空
      else return 0;
}



int longestValidParentheses(char* s)
{
    Stack stack;
    init_stack(&stack);
    
    int len = strlen(s);
    
    int ans = 0;
    int bg = 0;
    for(int i=0; i<len; ++i)
    {
        if(s[i]=='(') push(&stack,i);
          else{
            if(empty(&stack)) bg = i+1;
              else{
                pop(&stack);
                if(empty(&stack)) ans = max(ans,i-bg+1);
                else ans = max(ans,i-top(&stack));
          }
        }
        
    }

return ans;
}


/*@makuiyu
*1.如果当前栈为空，这说明当前的右括号并不构成括号匹配的子串，则l移到下一位置。
*2.如果当前栈不为空，弹出栈顶元素。此时，如果栈为空，说明加上当前的右括号可以构成括号匹配的子串，
*其子串长度就为l位置到当前位置的长度；如果栈不为空，则栈顶元素后面的括号对肯定是匹配的，
*因此子串长度就为栈顶元素位置的后一位置到当前位置的长度。
*/
