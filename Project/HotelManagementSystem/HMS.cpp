#include <iostream>
#include<fstream>
using namespace std;

//------ROOM STRUCT------
struct Room
{
    int RoomNo;
    string RoomType; // Single, Double, Suite
    bool IsRoomAvailable;
    double PricePerDay;
    Room *next;
};
Room *Head = NULL;

//--------Guest struct--------
struct Guest
{
    string Name;
    string RoomType;
    int RoomNo;
    int Days;
    double Bill;

    Guest *next;
};
Guest *guesthead = NULL;

//-----ADD ROOMS-------
void AddRooms(int Num, string Type)
{
    for (int i = 0; i < Type.length(); i++)
    {
        Type[i] = tolower(Type[i]);
    }
    Room *newRoom = new Room();
    newRoom->RoomNo = Num;
    newRoom->RoomType = Type;
    newRoom->IsRoomAvailable = true;
    newRoom->next = NULL;

    if (Type == "single")
    {
        newRoom->PricePerDay = 800;
    }
    else if (Type == "double")
    {
        newRoom->PricePerDay = 1500;
    }
    else if (Type == "suite")
    {
        newRoom->PricePerDay = 3000;
    }

    if (Head == NULL)
    {
        Head = newRoom;
    }
    else
    {
        Room *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newRoom;
    }
}
void initializeRooms()
{
    AddRooms(101, "single");
    AddRooms(102, "single");
    AddRooms(103, "single");

    AddRooms(201, "double");
    AddRooms(202, "double");
    AddRooms(203, "double");

    AddRooms(301, "suite");
    AddRooms(302, "suite");
    AddRooms(303, "suite");
}
void SaveRooms()
{
    //ofstream fout;   ofstream file me likhna 
    //fout.open("Room.txt");
    ofstream fout("Rooms.txt");

    Room *temp = Head;

    while (temp != NULL)
    {
        fout << temp->RoomNo << " "
             << temp->RoomType << " "
             << temp->IsRoomAvailable << " "
             << temp->PricePerDay << endl;

        temp = temp->next;
    }

    fout.close();
}
void LoadRooms()
{
    //ifstream fin;
    //fin.open("Room.txt");
    ifstream fin("Rooms.txt");

    if (!fin)
        return;

    Head = NULL;

    int no;
    string type;
    bool status;
    double price;

    while (fin >> no >> type >> status >> price)
    {
        Room *newRoom = new Room();

        newRoom->RoomNo = no;
        newRoom->RoomType = type;
        newRoom->IsRoomAvailable = status;
        newRoom->PricePerDay = price;
        newRoom->next = NULL;

        if (Head == NULL)
        {
            Head = newRoom;
        }
        else
        {
            Room *temp = Head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newRoom;
        }
    }

    fin.close();
}
// ------DISPLAY ROOMS------
void Display_Rooms()
{
    if (Head == NULL)
    {
        cout << "Rooms Not Found";
        return;
    }
    cout << "\n================ ROOM STATUS ================\n\n";
    cout << "RoomNo   RoomType   Price/Day   Status\n";
    cout << "-------------------------------------------\n";
    Room *temp = Head;
    while (temp != NULL)
    {
        cout << temp->RoomNo << "      "
             << temp->RoomType << "      "
             << temp->PricePerDay << "      "
             << (temp->IsRoomAvailable ? "Available" : "Booked")
             << endl;
        temp = temp->next;
        cout << endl;
    }
}

// add guest to the list
void addGuest(string name, string type, int RoomNo, int days, double bill)
{
    Guest *newGuest = new Guest;
    newGuest->Name = name;
    newGuest->RoomType = type;
    newGuest->RoomNo = RoomNo;
    newGuest->Days = days;
    newGuest->Bill = bill;
    newGuest->next = NULL;

    if (guesthead == NULL)
    {
        guesthead = newGuest;
    }
    else
    {
        Guest *temp = guesthead;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newGuest;
    }
}
void SaveGuests()
{
    ofstream fout("Guests.txt");

    Guest *temp = guesthead;

    while (temp != NULL)
    {
        fout << temp->Name << " "
             << temp->RoomType << " "
             << temp->RoomNo << " "
             << temp->Days << " "
             << temp->Bill << endl;

        temp = temp->next;
    }

    fout.close();
}
void LoadGuests()
{
    ifstream fin("Guests.txt");

    if (!fin)
        return;

    guesthead = NULL;

    string name, type;
    int room, days;
    double bill;

    while (fin >> name >> type >> room >> days >> bill)
    {
        addGuest(name, type, room, days, bill);
    }

    fin.close();
}
// display guest list
void displayGuest()
{
    cout << "\n================ GUEST LIST ================\n\n";
    if (guesthead == NULL)
    {
        cout << "No Guest Found" << endl;
    }
    cout << "Name\t        RoomType\tRoomNo\t      Days\t       Bill\n";
    cout << "----------------------------------------------------------------\n";

    Guest *tempGuest = guesthead;
    while (tempGuest != NULL)
    {
        cout << tempGuest->Name << "\t\t"
             << tempGuest->RoomType << "\t\t"
             << tempGuest->RoomNo << "\t\t"
             << tempGuest->Days << "\t\t"
             << tempGuest->Bill << endl;
        tempGuest = tempGuest->next;
    }

    cout << "==================================================\n";
}
//------Queue------
struct Queue
{
    string Guest_Name;
    string RoomType;
    int days;
    Queue *next;
};
Queue *front = NULL;
Queue *rear = NULL;

//------ENQUEUE-----
void EnQueue(string Name, string Type, int days)
{
    Queue *temp = new Queue;
    temp->Guest_Name = Name;
    temp->RoomType = Type;
    temp->days = days;
    temp->next = NULL;
    if (rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
void SaveQueue()
{
    ofstream fout("Queue.txt");

    Queue *temp = front;

    while (temp != NULL)
    {
        fout << temp->Guest_Name << " "
             << temp->RoomType << " "
             << temp->days << endl;

        temp = temp->next;
    }

    fout.close();
}void LoadQueue()
{
    ifstream fin("Queue.txt");

    if (!fin)
        return;

    front = rear = NULL;

    string name, type;
    int days;

    while (fin >> name >> type >> days)
    {
        EnQueue(name, type, days);
    }

    fin.close();
}
//------DEQUEUE------
Queue *DeQueue()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return NULL;
    }
    Queue *cur = front;

    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    return cur;
}

//-------SHOW QUEUE-------
void ShowQueue()
{
    cout << "\n================ WAITING QUEUE ================\n\n";
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "\n=============== WAITING QUEUE ===============\n\n";
    cout << "Guest Name     Room Type     Days\n";
    cout << "--------------------------------------------\n";
    Queue *temp = front;
    while (temp != NULL)
    {
        cout << temp->Guest_Name << "          "
             << temp->RoomType << "          "
             << temp->days << endl;

        temp = temp->next;
    }
    cout << "==============================================\n";
}

// SEARCH ROOM
Room *findRoom(string Type)
{
    Room *temp = Head;
    while (temp != NULL)
    {
        if (temp->RoomType == Type && temp->IsRoomAvailable)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// CHECKIN
void checkin()
{
    string Name, Type;
    int days;
    cout << "Enter GuestName: ";
    cin >> Name;
    cout << "Enter Roomtype: ";
    cin >> Type;
    cout << "Enter No. of days: ";
    cin >> days;

    Room *room = findRoom(Type);
    if (room == NULL)
    {
        cout << " NO Room Available." << endl;
        EnQueue(Name, Type, days);
        cout << "Added guest to the waiting queue";
        return;
    }
    double Bill = days * room->PricePerDay;
    addGuest(Name, room->RoomType, room->RoomNo, days, Bill);
    room->IsRoomAvailable = false;
    SaveGuests();
    SaveRooms();
    SaveQueue();

    cout << "\n************* CHECK-IN SUCCESS *************\n";
    cout << "Guest Name : " << Name << endl;
    cout << "Room Type  : " << room->RoomType << endl;
    cout << "Room No    : " << room->RoomNo << endl;
    cout << "Days       : " << days << endl;
    cout << "Status     : Booked\n";
    cout << "********************************************\n";
}

// CHECKOUT
void checkout()
{
    int RoomNo;
    cout << "Enter RoomNo: ";
    cin >> RoomNo;
    Room *temp = Head;
    while (temp != NULL)
    {
        if (temp->RoomNo == RoomNo)
        {
            if (temp->IsRoomAvailable)
            {
                cout << "Room is already available" << endl;
                return;
            }

            // search guest in the list
            Guest *curguest = guesthead;
            Guest *preguest = NULL;
            while (curguest != NULL)
            {
                if (curguest->RoomNo == RoomNo)
                {

                    cout << "\n************* CHECK-OUT BILL *************\n";
                    cout << "Guest Name : " << curguest->Name << endl;
                    cout << "Room Type  : " << curguest->RoomType << endl;
                    cout << "Room No    : " << curguest->RoomNo << endl;
                    cout << "Days       : " << curguest->Days << endl;
                    cout << "Total Bill : Rs. " << curguest->Bill << endl;
                    cout << "******************************************\n";

                    // cout << "GuestName: " << curguest->Name << endl;
                    // cout << "Room Type: " << curguest->RoomType << endl;
                    // cout << "Room No: " << curguest->RoomNo << endl;
                    // cout << "Days: " << curguest->Days << endl;
                    // cout << "Total Bill: " << curguest->Bill << endl;

                    if (preguest == NULL)
                    {
                        guesthead = curguest->next;
                    }
                    else
                    {
                        preguest->next = curguest->next;
                    }
                    delete curguest;
                    break;
                }
                preguest = curguest;
                curguest = curguest->next;
            }

            temp->IsRoomAvailable = true;

            // Queue Check
            Queue *cur = front;
            Queue *Pre = NULL;
            while (cur != NULL)
            {
                if (cur->RoomType == temp->RoomType)
                {
                    double Bill = cur->days * temp->PricePerDay;
                    addGuest(cur->Guest_Name, temp->RoomType, temp->RoomNo, cur->days, Bill);

                    // Assign room to waiting customer
                    temp->IsRoomAvailable = false;
                    cout << "Room assigned to waiting customer" << endl;
                    cout << "GuestName: " << cur->Guest_Name << endl;
                    cout << "RoomType: " << temp->RoomType << endl;
                    cout << "RoomNo: " << temp->RoomNo << endl;

                    // Remove guest from queue
                    if (Pre == NULL)
                    {
                        front = front->next;
                        if (front == NULL)
                        {
                            rear = NULL;
                        }
                    }
                    else
                    {
                        Pre->next = cur->next;
                        if (cur == rear)
                        {
                            rear = Pre;
                        }
                    }
                    delete cur;

                    SaveGuests();
                    SaveRooms();
                    SaveQueue();

                    return;
                }
                Pre = cur;
                cur = cur->next;
            }
            cout << "No waiting customer for this room type.\n";

            SaveGuests();
            SaveRooms();
            SaveQueue();
            return;
        }
        temp = temp->next;
    }
    cout << "Room Not found";
}
void SearchGuest()
{
    if (guesthead == NULL)
    {
        cout << "No Guest Found.\n";
        return;
    }

    string name;
    cout << "Enter Guest Name: ";
    cin >> name;

    Guest *temp = guesthead;

    while (temp != NULL)
    {
        if (temp->Name == name)
        {
            cout << "\nGuest Found\n";
            cout << "Name      : " << temp->Name << endl;
            cout << "Room Type : " << temp->RoomType << endl;
            cout << "Room No   : " << temp->RoomNo << endl;
            cout << "Days      : " << temp->Days << endl;
            cout << "Bill      : " << temp->Bill << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Guest Not Found.\n";
}
void SearchRoom()
{
    int roomNo;

    cout << "Enter Room Number: ";
    cin >> roomNo;

    Room *temp = Head;

    while (temp != NULL)
    {
        if (temp->RoomNo == roomNo)
        {
            cout << "\nRoom Found\n";
            cout << "Room No   : " << temp->RoomNo << endl;
            cout << "Room Type : " << temp->RoomType << endl;
            cout << "Price     : " << temp->PricePerDay << endl;

            if (temp->IsRoomAvailable)
                cout << "Status    : Available\n";
            else
                cout << "Status    : Booked\n";

            return;
        }

        temp = temp->next;
    }

    cout << "Room Not Found.\n";
}
void RoomSummary()
{
    int available = 0;
    int booked = 0;

    Room *temp = Head;

    while (temp != NULL)
    {
        if (temp->IsRoomAvailable)
            available++;
        else
            booked++;

        temp = temp->next;
    }

    cout << "\n===== ROOM SUMMARY =====\n";
    cout << "Available Rooms : " << available << endl;
    cout << "Booked Rooms    : " << booked << endl;
}
int main()
{
    LoadRooms();

    if (Head == NULL)
    {
        initializeRooms();
    }

    LoadGuests();
    LoadQueue();
    int choice;
    bool start = true;
    cout << "\n====================================================\n";
    cout << "           HOTEL MANAGEMENT SYSTEM\n";
    cout << "====================================================\n\n";

    while (start)
    {
        cout << "\n==================== MENU ====================\n";
        cout << "1. Display Rooms\n";
        cout << "2. Display Guest List\n";
        cout << "3. Check In Guest\n";
        cout << "4. Check Out Guest\n";
        cout << "5. Show Waiting Queue\n";
        cout << "6. Search Guest \n";
        cout << "7. Search Room\n";
        cout << "8. Total rooms \n";
        cout << "9. Exit\n";
        cout << "=============================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Display_Rooms();
            break;
        case 2:
            displayGuest();
            break;

        case 3:
            checkin();
            break;

        case 4:
            checkout();
            break;

        case 5:
            ShowQueue();
            break;
        case 6:
            SearchGuest();
            break;

        case 7:
            SearchRoom();
            break;

        case 8:
            RoomSummary();
            break;

        case 9:
            cout << "Exit ";
            cout << "Thank You For Using Hotel Management System.\n";
            start = false;
            break;

        default:
            cout << "Invalid";
        }
    }
    return 0;
}
