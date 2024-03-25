cmake_minimum_required(VERSION 3.0.2)
project(topic_ex)


find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

add_message_files(
      FILES
      Age.msg
    )

generate_messages(
      DEPENDENCIES
      std_msgs
) # Dont Forget to uncoment here TOO

catkin_package(
 CATKIN_DEPENDS roscpp std_msgs message_runtime   
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(publish_age src/publish_age.cpp)
add_dependencies(publish_age ${publish_age_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(publish_age
   ${catkin_LIBRARIES}
 )
add_dependencies(publish_age topic_ex_generate_messages_cpp)