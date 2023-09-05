#include <bits/stdc++.h>

using namespace std;

double calculateMean(vector<double>& data) {
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    return sum / data.size();
}

double calculateSlope(vector<double>& x, vector<double>& y, double xMean, double yMean) {
    double numerator = 0.0;
    double denominator = 0.0;
    for (int i = 0; i < x.size(); i++) {
        numerator += (x[i] - xMean) * (y[i] - yMean);
        denominator += pow((x[i] - xMean), 2);
    }
    return numerator / denominator;
}

double calculateIntercept(double xMean, double yMean, double slope) {
    return yMean - (slope * xMean);
}

double predictStockPrice(double x, double slope, double intercept) {
    return (slope * x) + intercept;
}

int main() {
    ifstream file("houses.csv");
    vector<vector<double>> data;
    string line;
    while (getline(file, line))
    {
        vector<double> row;
        double value;
        char comma;
        istringstream ss(line);
        while (ss >> value)
        {
            row.push_back(value);
            if (ss >> comma)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        data.push_back(row);
    }
    
    vector<double> x;
    vector<double> y;
    
    for (int i = 0; i < data.size(); i++)
    {
        x.push_back(data[i][0]);
        y.push_back(data[i][1]);
     }
     
     double xMean = calculateMean(x);
     double yMean = calculateMean(y);
     double slope = calculateSlope(x, y, xMean, yMean);
     double intercept = calculateIntercept(xMean, yMean, slope);
     
     double xValue; 
     cin >> xValue;
     
     double predictedPrice = predictStockPrice(xValue, slope, intercept);
     
     cout << "Predicted price for " << xValue << " is: " << predictedPrice << endl;

return 0;
}
