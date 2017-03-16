#include "function.h"

Function::Function(){
    x = nullptr;
    y = nullptr;
    period = nullptr;
    periodSize = 0;
}

Function::Function(const QVector<qreal>& x, qreal (*f)(qreal)){
    if(!this->x){
        this->x = new QVector<qreal>(x);
    }

    if(!this->y){
        this->y = new QVector<qreal>();
    }

    for(qint64 i = 0; i < x.length(); i++){
        y->append(f(x.at(i)));
    }

    this->periodSize = getPeriodSize();
    this->period = new QVector<qreal>();
    this->period = getPeriod();
}

qreal Function::getMaxt(bool flag){
    qreal max = 0;
    if(flag){
        max = this->y->at(0);
        for(qint64 i = 1; i < this->y->length(); i++){
            if(this->y->at(i) > max){
                max = this->y->at(i);
            }
        }
    }else{
        max = this->x->at(0);
        for(qint64 i = 1; i < this->x->length(); i++){
            if(this->x->at(i) > max){
                max = this->x->at(i);
            }
        }
    }
    return max;
}

Function::Function(const Function &f){

}

QVector<qreal> Function::getDiscretValues(qint64 step, bool flag){
    QVector<qreal>* discretValues = new QVector<qreal>();

    if(flag){
        for(qint64 i = 0; i < this->y->length(); i += step){
            discretValues->push_back(this->y->at(i));
        }
    }else{
        for(qint64 i = 0; i < this->x->length(); i += step){
            discretValues->push_back(this->x->at(i));
        }
    }
    return *discretValues;
}

qint64 Function::getPeriodSize(){
    qreal max = getMax();

    qint64 startIndex = 0, endIndex = 0, count = 0;
    for(qint64 i = 0; i < this->y->length(); i++){
        if(compareWithEpsilon(roundWithPrecision(this->y->at(i),4), roundWithPrecision(max, 4))){
            if(count == 0){
                startIndex = i;
                count++;
            }else{
                if(count == 1){
                    endIndex = i;
                    break;
                }
            }
        }
    }
    return endIndex - startIndex;
}

QVector<qreal> Function::getPeriod(){
    return this->period;
}


