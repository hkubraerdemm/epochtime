//
//  main.c
//  algoritmaödev
//
//  Created by Hatice Kübra Erdem on 22.11.2024.
//

#include <stdio.h>

//sharpe oranını hesaplayan fonksiyon//
double hesaplaSharpeOrani(double portfoyGetirisi, double risksizGetiri, double standartSapma) {
    return (portfoyGetirisi - risksizGetiri) / standartSapma;
}
// risk analizi yapan fonksiyon//
void riskAnalizi(double sharpeOrani) {
    if(sharpeOrani > 1) {
        printf("risk analizi: iyi bir yatırım sharpe orani: %.2f\n", sharpeOrani);
    } else if(sharpeOrani > 0 && sharpeOrani <= 0) {
        printf("risk analizi: kabul edilebilir bir risk. sharpe orani: %.2f\n", sharpeOrani);
    } else {
        printf("risk analizi: yüksek risk, dikkatli olunmalı! sharpe orani: %.2f\n", sharpeOrani);
    }
}
int main() {
    double portfoyGetirisi, risksizGetiri, standartSapma;
    
    // kullanıcıdan verileri al//
    printf("portföy getirisi (yüzde olarak): ");
    scanf("%lf", &portfoyGetirisi);
    printf("risksiz getiri oranı (yüzde olarak): ");
    scanf("%lf", &risksizGetiri);
    printf("portföy standart sapması: ");
    scanf("%lf", &standartSapma);
    
    //yüzde değerlerini oranlara çevir//
    portfoyGetirisi /= 100;
    risksizGetiri /= 100;
    
    // sharpe oranını hesapla//
    double sharpeOrani = hesaplaSharpeOrani(portfoyGetirisi, risksizGetiri, standartSapma);
    
    // risk analizi yap
    riskAnalizi(sharpeOrani);
    
    return 0;
}
