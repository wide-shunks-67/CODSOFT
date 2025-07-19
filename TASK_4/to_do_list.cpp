#include<bits/stdc++.h>
using namespace std;
struct Task{
    string description;
    bool completed;
};

void add_task(vector<Task> &tasks){
    string descrip;
    cout<<"Enter the task descprition: ";
    cin.ignore();
    getline(cin,descrip);
    tasks.push_back({descrip,false});
    cout<<"Task added succesfully\n";
}

void view_task(const vector<Task> &tasks){
    if(tasks.empty()){
        cout<<"No tasks found.\n";
        return;
    }
    cout<<"\n To-Do List: \n";
    for(size_t i=0; i< tasks.size(); i++){
        cout<<i + 1<<". ["<<(tasks[i].completed? "Done":"Not Done")<<"] "<<tasks[i].description<<"\n";
    }
    cout<<endl;
}

void remove_task(vector<Task> &tasks){
    int index;
    if(tasks.empty())return ;
    view_task(tasks);
    cout<<"Enter the task number you want to remove: ";
    cin>>index;
    if(index>=1 && index<=tasks.size()){
        tasks.erase(tasks.begin() + index - 1);
        cout<<"Tasks removed succesfully.\n";
    }
    else{
        cout<<"Invalid task number.\n";
    }
}

void mark_completed(vector<Task> &tasks){
    int index;
    view_task(tasks);
    if(tasks.empty())return;
    
    cout<<"Enter the task number you want to mark as completed: ";
    cin>>index;
    if(index>=1 && index<=tasks.size()){
        tasks[index-1].completed=true;
        cout<<"Task marked as completed.\n";
    }
    else{
        cout<<"Invalid task number\n";
    }
}
int main(){
    vector<Task>tasks;
    int choice; 
    do{
        cout<<"\n===TO-DO-LIST MENU===\n";
        cout<<"1. Add task.\n";
        cout<<"2. Veiw tasks.\n";
        cout<<"3. Mark task as completed.\n";
        cout<<"4. Remove task.\n";
        cout<<"5. Exit.\n";
        cout<<"Enter your choice (1-5): ";
        cin>>choice;
        switch(choice){
            case 1: add_task(tasks); break;
            case 2: view_task(tasks); break;
            case 3: mark_completed(tasks); break;
            case 4: remove_task(tasks); break;
            case 5: cout<<"Thank you!\n"; break;
            default: cout<<"Invalid choice. Try again.\n";
        }
    }
    while(choice!=5);
    return 0;
}