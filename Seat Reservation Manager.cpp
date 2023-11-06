class SeatManager {
public:
    int arr[100001] = {0};
    int curr = 0; 
    SeatManager(int n) {
        curr = 1;
    }
    
    int reserve() {
        arr[curr] = curr;
        int temp = curr;
        while(arr[curr] != 0) curr++;
        return temp;
    }
    
    void unreserve(int seatNumber) {
       arr[seatNumber] = 0;
       curr = min(curr, seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
