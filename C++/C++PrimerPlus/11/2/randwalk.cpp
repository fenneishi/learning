

# include<iostream>
# include<cstdlib>
# include<ctime>
# include"vector.h"
using namespace std;
using namespace VECTOR;



int main(int argc, char const *argv[])
{
    double target;

    // 迭代向量
    Vector result(0,0);

    // 定义迭代增量
    Vector step(0,0);//增量向量
    double stepLength;//增量向量的模长
    double stepDirection;//增量向量的方向

    // 进入游戏
    cout<<"play game?(y or n):";
    char fileNum='a';
    while(cin.get()!='n')
    {
        // 打开文件
        ofstream fout;
        string fileName=string("game_")+char(fileNum++);
        fout.open(fileName);

        // 获取游戏目标
        cout<<"input game target:";
        (cin>>target).get();
        fout<<"target distance:"<<target<<endl;

        // 获取步长
        cout<<"input the step length:";
        (cin>>stepLength).get();
        fout<<"step length:"<<stepLength<<endl;

        // 进行迭代
        int count=0;//迭代次数
        fout<<count<<":"<<result<<endl;//输出初始情况
        while(result.getmag()<target)
        {
            stepDirection=rand()%360;//随机获取迭代方向
            step.reset(stepLength,stepDirection,Vector::POL);//设置迭代向量
            result=result+step;//迭代
            count++;//迭代次数统计
            fout<<count<<":"<<result<<endl;//输出本次迭代结果
        }

        //完成任务后，输出最终结果
        fout<<"finish the target!"<<endl;
        fout<<"steps:"<<count<<endl;//迭代合计步数
        fout<<"result(RECT):"<<result<<endl;//最终结果（RECT模式下）
        result.toPOL();
        fout<<"result(POL):"<<result<<endl;//最终结果（POL模式下）
        fout<<"average distance:"<<result.getmag()/count<<endl;//每步平均距离

        //迭代向量重置
        result.reset(0,0);

        // 是否开始新的一轮迭代
        cout<<"finish the target,result has writed into file:"<<fileName<<endl;
        cout<<"play game again?(y or n):";
    }

    
    return 0;
}
