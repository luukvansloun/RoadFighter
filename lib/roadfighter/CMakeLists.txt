SET(RF_SRC EntityFactory.h EntityFactory.cpp Entity.h Entity.cpp PlayerCar.h PlayerCar.cpp RacingCar.h RacingCar.cpp
        World.h World.cpp Truck.cpp Truck.h Lorry.cpp Lorry.h Bullet.cpp Bullet.h)

SET(LIB_TYPE SHARED)

ADD_LIBRARY(roadfighter ${LIB_TYPE} ${RF_SRC})