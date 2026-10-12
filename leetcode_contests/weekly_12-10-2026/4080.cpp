class BusBooking {
public:
    vector<vector<bool>>arr;
    vector<vector<int>>cost;
    int total;
    int Booking;
    int n;
    BusBooking(int n) {
        this->n=n;
        arr.assign(n,vector<bool>(4,false));
        cost.assign(n,vector<int>(4,0));
        total=0;
        Booking=0;
    
        
        
        
    }
    
    void toggle(string seat) {
        int row=stoi(seat.substr(1))-1;
        int col;
        if(seat[0]=='A') col=0;
        else if(seat[0]=='B') col=1;
        else if(seat[0]=='C') col=2;
        else col=3;
        if(arr[row][col]){
            total-=cost[row][col];
            arr[row][col]=false;
            Booking--;
            cost[row][col]=0;
        }
        else{
            int time=1;
        if(col==0 && arr[row][1]){
            time=3;
        }
        else if(col==3 && arr[row][2]){
            time=3;
            
        }
        arr[row][col]=true;
        cost[row][col]=time;
        Booking++;
        total+=time;
        } 
        
        
        
    }
    
    int getTotalTime() {
        return total;
        
    }
    
    int getMinTime() {
        return Booking;
        
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */