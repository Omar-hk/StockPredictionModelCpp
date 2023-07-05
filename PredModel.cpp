#include <bits/stdc++.h>

using namespace std;

// Function to calculate the mean of a vector
double calculateMean(vector<double>& data) {
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    return sum / data.size();
}

// Function to calculate the slope (beta1) of the linear regression line
double calculateSlope(vector<double>& x, vector<double>& y, double xMean, double yMean) {
    double numerator = 0.0;
    double denominator = 0.0;
    for (int i = 0; i < x.size(); i++) {
        numerator += (x[i] - xMean) * (y[i] - yMean);
        denominator += pow((x[i] - xMean), 2);
    }
    return numerator / denominator;
}

// Function to calculate the intercept (beta0) of the linear regression line
double calculateIntercept(double xMean, double yMean, double slope) {
    return yMean - (slope * xMean);
}

// Function to predict the stock price using the linear regression model
double predictStockPrice(double x, double slope, double intercept) {
    return (slope * x) + intercept;
}

int main() {
    // Sample data
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {10, 20, 30, 40, 50};

    // Calculate the mean of x and y
    double xMean = calculateMean(x);
    double yMean = calculateMean(y);

    // Calculate the slope and intercept of the linear regression line
    double slope = calculateSlope(x, y, xMean, yMean);
    double intercept = calculateIntercept(xMean, yMean, slope);

    // Predict the stock price for a given value of x
    double xValue; cin >> xValue;
    double predictedPrice = predictStockPrice(xValue, slope, intercept);

    cout << "Predicted stock price for x = " << xValue << ": " << predictedPrice << endl;

    return 0;
}