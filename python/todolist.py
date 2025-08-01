task =[]
print("------------------WELCOME TO TO-DO-LIST APP--------------------")
n=int(input("Enter number of works:"))
for x in range(n):
    val=input(f"Enter {x+1}  work =")
    task.append(val)
print("YOUR LIST")
for x in range(len(task)):
    print(f"{task[x]}")

op=(input("DO you want to edit your list (yes/No):"))
if op== "yes" or op=="YES":
 print("Do You Want to\n1.Add task\n2.Remove Task\n3.View Tassk\n4.Clear all Task\n5.Exit")
 ch=int(input("Enter your choice:"))
 match ch:
        case 1:
            num=int(input("Enter number of task you want to add:"))
            for i in range(num):
                value=int(input("Enter priority number:"))
                tasks=input("Enter work:")
                task.insert(value-1,tasks)
            print("updated list-")
            for x in range(len(task)):
               print(f"{task[x]}")
            print(*task)
        case 2:
            n=int(input("Enter  no of work to remove:"))
            for i in range(n):
                ind=int(input("Enter task number to remove:"))
                n1=ind-1
                task.pop(n1)
         
                print("updated list")
                print(*task)

        case 3:
               print("Your Task List")
               for i in range(len(task)):
                   print(f"{task[i]}")
                   
        case 4:
                print("All task clear")
                task.clear()
        case 5:
           print("Thank you for using this app")  
           print("Exiting.....")      
        case _:
             print("Invalid number")

else:
     print("Thank you for using this app")



 
 