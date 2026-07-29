class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // get the freq of each task to ready 
        
        

        vector<int>freq(26,0);

        for(auto task: tasks){
            freq[task-'A']++;
        }


        // sort on basis of maxfreq 
        sort(freq.begin(),freq.end());



        int maxFreq=freq[25]; // last element ki freq is max frequency 


        // ab dekhne honge hame empty slots

        int empty_slots=(maxFreq-1)*n;


        // bache huye tasks khali slots mei rakhdo 



        for(int i=24; i>=0 && freq[i]>0;i--){
            empty_slots-=min(maxFreq-1,freq[i]);
        }


          empty_slots=max(0,empty_slots); // if slots negative 



          return tasks.size()+empty_slots;
    }
};
