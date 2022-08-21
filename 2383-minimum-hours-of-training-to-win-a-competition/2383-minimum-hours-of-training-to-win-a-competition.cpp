class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        
        int sumEnergy=0;
        for(int i=0;i<energy.size();i++)
        {
            sumEnergy += energy[i];
        }
        int en = 0;
        if(sumEnergy >= initialEnergy)
            en = sumEnergy - initialEnergy + 1;
        
        int exp = 0;
        for(int i=0;i<energy.size();i++)
        {
            if(experience[i] >= initialExperience)
            {
                int diff = (experience[i] - initialExperience)+1;
                initialExperience += diff ;
                exp += diff;
            }
            
            initialExperience += experience[i];
            
        }
        return en+exp;

        
    }
};