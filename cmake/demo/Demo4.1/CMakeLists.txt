# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo4)

set(CMAKE_INCLUDE_CURRENT_DIR ON)



# 整个文本，都是给信息的，只要各方面的信息给全了，就OK了
# 所以不是特别强调编写者给信息的逻辑，有些信息它通过上下文自动就推断出了，只要你不特别指定的话，例如


# 解决了2个问题
# 1、交互式的方式从键盘获取真正的USE_MYMATH选项的值
# 2、根据USE_MYMATH的值去生成config.h文件
#     1、如果USE_MYMATH=on,那么config.h里面就定义常量USE_MYMATH
#     2、如果USE_MYMATH=OFF,那么config.h里面就不定义USE_MYMATH常量
# 
# 为什么可以解决这2个问题，因为提供所有必要的信息：
# 1、config.h.in 文件路径
# 2、config.h 文件路径
# 3、开关名称(并且创立了开关，并提供了默认值)
# 4、常量名称(写在config.h.in文件中))
# 
# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_SOURCE_DIR}/config.h"
  )

# 是否使用自己的 MathFunctions 库
option (USE_MYMATH
	   "Use provided math implementation" ON)






# 命令解释
#   1、include_directories ("${PROJECT_SOURCE_DIR}/math")
#       ------>源文件到哪里去#include <math.h>
#   2、add_subdirectory (math)
#       ------>编译出静态库二进制文件libMathFunctions.a，
#       ------>把libMathFunctions.a放在${PROJECT_BINARY_DIR}/math中

# 实际上，我猜测，所有的编译目标都会默认放在${PROJECT_BINARY_DIR}目录下：
#   1、编译目标包括生成动态库，静态库，最终目标文件(可执行文件)
#   2、特殊的是，通过add_subdirectory(math)调用的子目录的编译目标会放在${PROJECT_BINARY_DIR}/math(同名子目录下)
#   3、target_link_libraries(...)时，肯定会通过先在${PROJECT_BINARY_DIR}及其所有子目录下找库文件。

# 解决了一个问题：如果开关=on,要干什么？
# 1、编译静态库：creat出静态库文件:---->add_subdirectory (math) 交给子文件夹中的CMakeLists.txt去干。
# 2、让CMake知道到哪里去找静态库文件的头文件：include_directories ("${PROJECT_SOURCE_DIR}/math")
# 2、让CMake能够找到静态库文件：
#     1、寻找位置：---->add_subdirectory (math) 
#     2、文件名称：---->add_subdirectory (math) 
#

# 是否加入 MathFunctions 库
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions) #EXTRA_LIBS应该是一个预定义变量=外部库文件的名称列表。
endif (USE_MYMATH)







# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable (Demo ${DIR_SRCS})
target_link_libraries (Demo  ${EXTRA_LIBS})


# 隐藏信息：
# 1、主目录的CMakeList.txt
#   1、add_executable (Demo ${DIR_SRCS})
#       1、参数1的默认存放地址为:${PROJECT_BINARY_DIR}
#       2、参数2的默认寻找地址为:${PROJECT_SOURCE_DIR}
#   2、target_link_libraries()
#       1、参数1的默认存放地址为:${PROJECT_BINARY_DIR}
#       2、参数2的默认寻找地址为:${PROJECT_SOURCE_DIR}及其子文件夹
# 2、子目录/math里的CMakeList.txt
#   1、add_library (参数1 参数2)
#       1、参数1的默认存放地址为:${PROJECT_BINARY_DIR}/math
#       2、参数2的默认寻找地址为:${PROJECT_SOURCE_DIR}/math
# 3、add_subdirectory (math)
#   1、执行子目录里的CMakeList.txt
#   2、子目录CMakeList.txt里定义的变量，主目录CMakeList.txt里也可以访问。



# 你要提供：
#   1、特殊头文件路径添加(不在默认头文件搜索路径的头文件)
#   2、源文件名称列表
#   3、可执行文件名称(creat时，链接时)
#   4、库文件名称(creat时，链接时)



# 核心目标：
#   1、告诉cmake源文件在哪？都叫什么？
#   2、创建库文件，并告诉cmake库文件在哪？都叫什么？
#   3、告诉目标文件(可执行文件)叫什么，放到哪里？
#   4、建立目标文件、源文件、库文件之间链接。
#   小目标：特殊头文件路径添加。

