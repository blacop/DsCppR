//数据结构——链栈的基本操作
//http://www.cnblogs.com/gentleming/archive/2010/07/21/1781827.html
//尾插法
#include <iostream>
using namespace std;

typedef struct stacknode
{
    int data;
    struct stacknode * next;
}StackNode,* LinkStack;

//判栈空
int StackEmpty(LinkStack top)
{
      if(top->next==NULL)
          return 1;
      else
          return 0;
}
//入栈函数
LinkStack Push(LinkStack top,int value)
{
    StackNode * newp = (StackNode *)malloc(sizeof(StackNode));
    if(newp != NULL)
    {
        newp->data=value;
        newp->next=top->next;
        top->next=newp;
    }
    else
        cout<<"No memory available"<<endl;
    return top;

}
//出栈函数
int Pop(LinkStack top)
{
    StackNode * temp;
    int t;
    if(StackEmpty(top))
        cout<<"the stack is empty"<<endl;
    else
    {
        temp=top->next;
        t=temp->data;
        top->next = temp->next;
        free(temp);
    }
    return t;
}
//打印函数
void PrintStack(LinkStack top)
{
    if(top->next==NULL)
        cout<<"the stack is empty"<<endl;
    else
    {
        while(top->next!=NULL)
        {
            cout<<top->next->data<<"  ";
            top=top->next;
        }
    }
}
//取栈顶元素
int StackTop(LinkStack top)
{
      if(StackEmpty(top))
           cout<<"the Stack is empty"<<endl;
      return top->next->data;
}
//栈的长度
int StackLen(LinkStack top)
{
    int len=0;
        while(top->next!=NULL)
        {
            len++;
            top=top->next;
        }

    return len;
}
//销毁栈
void DestroyStack(LinkStack top)
{
     LinkStack q;
     while(top)
     {
          q=top->next;
          delete top;
          top=q;
     }
     printf("销毁成功");

}
//栈初始化
void InitStack(LinkStack top)
{  
    top->next=NULL; 
}
//前导函数
void instruction(void)
{
    cout<<"0------退出程序"<<endl
        <<"1------入栈操作"<<endl
        <<"2------出栈操作"<<endl
        <<"3------取栈顶元素"<<endl
        <<"4------判断栈是否为空"<<endl
        <<"5------返回栈的元素个数"<<endl
        <<"6------####初始化栈###"<<endl
        <<"7------显示栈"<<endl
        <<"8------销毁栈"<<endl
        <<"9------退出程序"<<endl;
}
int main()
{
    LinkStack top;
    top = (LinkStack)malloc(sizeof(StackNode));    //注意    

    instruction();
    int i,value;
        cin>>i;
    while(i)    //输入0也可以退出循环
    {
        switch(i)
        {
            
            case 1:        //入栈操作
                InitStack(top);
                cout<<"Input an integer"<<endl;
                cin>>value;
                while(value!=0)
                {
                    Push(top,value);    //入栈
                    cin>>value;
                }
                PrintStack(top);    //打印栈
                cout<<endl;
                break;
            case 2:        //出栈操作
                if(top->next!=NULL)
                    cout<<"the popped value is:"<<Pop(top)<<endl;    //出栈
                else
                    cout<<"the stack is empty"<<endl;
                break;
            case 3:        //取栈顶元素
                if(StackEmpty(top)==1)
                    cout<<"is empty"<<endl;
                else
                    cout<<StackTop(top)<<endl;
                break;
            case 4:        //判断栈是否为空
                if(StackEmpty(top)==1)
                    cout<<"is empty"<<endl;
                else
                    cout<<"is not empty"<<endl;
                break;
            case 5:        //返回栈的元素个数
                if(StackEmpty(top)==1)
                    cout<<"is empty"<<endl;
                cout<<StackLen(top)<<endl;
                cout<<endl;
                break;
            case 6:        //初始化栈
                InitStack(top);break;
            case 7:        //显示栈
                PrintStack(top);
                cout<<endl;break;
            case 8:        //销毁栈
                DestroyStack(top);
                cout<<endl;break;
            case 9:
                goto end;
            default:
                cout<<"Invalid choice"<<endl;break;
        }
        instruction();    
        cin>>i;
    }
    end:;    //利用goto语句退出循环
    return 0;
}

//简短的出栈入栈函数，数组实现
/*
    #include <stdio.h>
    int stack[100]; //100个栈空间
    int* sp = stack; //栈指针指向栈底
    #define push( i ) { *sp++ = i; } //push一个数
    #define pop() (*--sp) //pop一个数并返回

    int main()
    {
        int i;
        for ( i = 0; i < 10; ++i )//push 0~9
        push( i );
        for ( i = 0; i < 10; ++i )//输出9~0
        printf( "%d ", pop() ) ;
    }
*/