SET(RF_SRC EntityFactory.h EntityFactory.cpp Entity.h Entity.cpp PlayerCar.h PlayerCar.cpp RacingCar.h RacingCar.cpp
        World.h World.cpp)

SET(LIB_TYPE SHARED Truck.cpp Truck.h Lorry.cpp Lorry.h)

ADD_LIBRARY(roadfighter ${LIB_TYPE} ${RF_SRC})