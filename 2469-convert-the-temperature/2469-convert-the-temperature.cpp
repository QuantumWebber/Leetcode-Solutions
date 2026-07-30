class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double temp_kel=celsius+273.15;
        double temp_fahr=celsius*1.80+32.00;
        return{temp_kel,temp_fahr};
    }
};