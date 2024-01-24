#include <iostream>
#include <string>
#include <vector>

//定数
const int row_max = 10;
const int col_max = 10;
const int goal = 10;
const int gas_station = 1;
const int sky_tree =2;
const int car_position = 3;
const int on_landmark = 4;

struct car
{
    char direction{'S'}; //方向(North, South, West, East)
    int speed{0}; //速度
    int position[2] = {0, 0}; //位置({row, col})
    int fuel = 100;
};

//速度と方向の制御
void control(int command, car& car){
    switch (command)
    {
    case 0:
        car.speed = 0;
        break;

    case 1:
        if(car.direction=='N'){
            car.direction='W';
        }else if(car.direction=='E'){
            car.direction='N';
        }else if(car.direction=='S'){
            car.direction='E';
        }else if(car.direction=='W'){
            car.direction='S';
        }
        break;

    case 2:
        if(car.direction=='N'){
            car.direction='E';
        }else if(car.direction=='E'){
            car.direction='S';
        }else if(car.direction=='S'){
            car.direction='W';
        }else if(car.direction=='W'){
            car.direction='N';
        }
        break;

    case 3:
        break;

    case 4:
        car.speed++;
        break;

    case 5:
        if(car.speed > 0){
            car.speed--;
        }
        break;
    
    default:
        break;
    }

    return;
}

//移動の制御
void move(car& car){
    switch (car.direction)
    {
    case 'N':
        {
        if(car.position[0] - car.speed >= 0){
            car.position[0] -= car.speed;
        }else {
            std::cout << "You cannot move. Please Retry." << std::endl;
        }
        break;
        }
    
    case 'S':
        {
        if(car.position[0] + car.speed < row_max){
            car.position[0] += car.speed;
        }else {
            std::cout << "You cannot move. Please Retry." << std::endl;
        }
        break;
        }
        
    case 'W':
        {
        if(car.position[1] - car.speed >= 0){
            car.position[1] -= car.speed;
        }else {
            std::cout << "You cannot move. Please Retry." << std::endl;
        }
        break;
        }

    case 'E':
        {
        if(car.position[1] + car.speed < col_max){
            car.position[1] += car.speed;
        }else {
            std::cout << "You cannot move. Please Retry." << std::endl;
        }
        break;
        }

    default:
        break;
    }

    return;
}

//燃料の消費
void fuel_calc(car& car){
    if(car.fuel - car.speed*2 > 0){
        car.fuel = car.fuel - car.speed*2;
    } else {
        car.fuel = 0;
    }
}

int main(){
    //初期化
    int user_input{0};
    car user_car;
    std::vector<std::vector<int>> map(row_max, std::vector<int>(col_max, 0));

    map[row_max-1][col_max-1] = goal;
    map[0][col_max-1] = gas_station;
    map[row_max-1][0] = gas_station;
    map[row_max/2][col_max/2] = sky_tree;

    std::cout << "Welcome to Drive Adventure!" << std::endl;

    //ゲーム本体処理
    while (true)
    {
        //地図前回値の消去
        for(int row=0; row<row_max; row++){
            for(int col=0; col<col_max; col++){
                if(map[row][col] == car_position){
                    map[row][col] = 0;
                } else if (map[row_max-1][col_max-1] == on_landmark){
                    map[row_max-1][col_max-1] == goal;
                } else if (map[0][col_max-1] == on_landmark){
                    map[0][col_max-1] = gas_station;
                } else if (map[row_max-1][0] == on_landmark){
                    map[row_max-1][0] = gas_station;
                } else if (map[row_max/2][col_max/2] == on_landmark){
                    map[row_max/2][col_max/2] = sky_tree;
                }
            }
        }

        //地図への自車位置反映
        if(map[user_car.position[0]][user_car.position[1]] == on_landmark){
            map[user_car.position[0]][user_car.position[1]] = on_landmark;
        }else if(map[user_car.position[0]][user_car.position[1]] == 0){
            map[user_car.position[0]][user_car.position[1]] = car_position;
        }else if(map[user_car.position[0]][user_car.position[1]] == goal){
            map[user_car.position[0]][user_car.position[1]] = on_landmark;
            std::cout << "Goal. Game Clear!" << std::endl;
            break;
        }else if(map[user_car.position[0]][user_car.position[1]] == gas_station){
            map[user_car.position[0]][user_car.position[1]] = on_landmark;
            std::cout << "gas station. Fuel refill." << std::endl;
            user_car.fuel = 100;
        }else if(map[user_car.position[0]][user_car.position[1]] == sky_tree){
            map[user_car.position[0]][user_car.position[1]] = on_landmark;
            std::cout << "SkyTree." << std::endl; 
        }else {
            map[user_car.position[0]][user_car.position[1]] = car_position;
        }

        std::cout << std::endl;

        //地図の描画
        for(int i=0 ; i < row_max; i++){

            if(i == 0){
                for(int j=0; j<col_max+2; j++ ){
                std::cout << "-";
                }
                std::cout << std::endl;
            }

            for(int k=0; k < col_max; k++){
                if(k==0){
                    if(map[i][k] == goal){
                        std::cout << "|G";
                    } else if(map[i][k] == car_position){
                        std::cout << "|C";
                    } else if(map[i][k] == gas_station){
                        std::cout << "|g";
                    } else if(map[i][k] == sky_tree){
                        std::cout << "|S";
                    } else if(map[i][k] == on_landmark){
                        std::cout << "|O";
                    } else {
                        std::cout << "| ";
                    }
                }else if(k==(col_max-1)){
                    if(map[i][k] == goal){
                        std::cout << "G|";
                    } else if(map[i][k] == car_position){
                        std::cout << "C|";
                    } else if(map[i][k] == gas_station){
                        std::cout << "g|";
                    } else if(map[i][k] == sky_tree){
                        std::cout << "S|";
                    } else if(map[i][k] == on_landmark){
                        std::cout << "O|";
                    } else {
                        std::cout << " |";
                    }
                }else {
                    if(map[i][k] == goal){
                        std::cout << "G";
                    } else if(map[i][k] == car_position){
                        std::cout << "C";
                    } else if(map[i][k] == gas_station){
                        std::cout << "g";
                    } else if(map[i][k] == sky_tree){
                        std::cout << "S";
                    } else if(map[i][k] == on_landmark){
                        std::cout << "O";
                    } else {
                        std::cout << " ";
                    }

                }
            }
            std::cout << std::endl;

            if(i == row_max-1 ){
                for(int l=0; l<col_max+2; l++ ){
                std::cout << "-";
                }
                std::cout << std::endl;
            }
        }

        std::cout << "Fuel level: " << user_car.fuel << " %" << std::endl;
        std::cout << std::endl;

        if(user_car.fuel == 0){
            std::cout << "Fuel empty. Game Over." << std::endl;
            break;
        }

        //ユーザ入力
        std::cout << "Please Input Command" << std::endl 
        << "stop:0 / turn left:1 / turn right:2 / continue straight:3 / accelerate:4 / decelerate:5 / exit:6 " << std::endl;
        std::cin >> user_input;

        if( (user_input > 6) || (user_input < 0)){
            std::cout << "Invalid Input. Please retry." << std::endl;
            continue;
        } else if(user_input==6) {
            break;
        }
        std::cout << std::endl;

        //車両の制御
        control(user_input, user_car);
        move(user_car);
        fuel_calc(user_car);

    }
    return 0;
}