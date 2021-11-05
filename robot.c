#include "robot.h"
#include "stdbool.h"

void setup_robot(struct Robot *robot)
{
    // robot->x = OVERALL_WINDOW_WIDTH / 2;
    // robot->y = OVERALL_WINDOW_HEIGHT - 50;
    // robot->true_x = OVERALL_WINDOW_WIDTH / 2 - 50;
    // robot->true_y = OVERALL_WINDOW_HEIGHT - 50;
    // robot->width = ROBOT_WIDTH;
    // robot->height = ROBOT_HEIGHT;
    // robot->direction = 0;
    // robot->angle = 0;
    // robot->currentSpeed = 0;
    // robot->crashed = 0;
    // robot->auto_mode = 0;

    /** // Basic maze 1
    robot->x = 270;
    robot->y = 460;
    robot->true_x = 270;
    robot->true_y = 460;
    robot->width = ROBOT_WIDTH;
    robot->height = ROBOT_HEIGHT;
    robot->direction = 0;
    robot->angle = 0;
    robot->currentSpeed = 0;
    robot->crashed = 0;
    robot->auto_mode = 0;
    **/

    // Basic maze 2
    robot->x = 620;
    robot->y = 380;
    robot->true_x = 620;
    robot->true_y = 380;
    robot->width = ROBOT_WIDTH;
    robot->height = ROBOT_HEIGHT;
    robot->direction = 0;
    robot->angle = 270;
    robot->currentSpeed = 0;
    robot->crashed = 0;
    robot->auto_mode = 0;

    /**
    // Basic maze 3
    robot->x = 640 - 10 - 270;
    robot->y = 460;
    robot->true_x = 640 - 10 - 270;
    robot->true_y = 460;
    robot->width = ROBOT_WIDTH;
    robot->height = ROBOT_HEIGHT;
    robot->direction = 0;
    robot->angle = 0;
    robot->currentSpeed = 0;
    robot->crashed = 0;
    robot->auto_mode = 0;
    **/

    /**
    // Basic maze 4
    robot->x = 0;
    robot->y = 380;
    robot->true_x = 0;
    robot->true_y = 380;
    robot->width = ROBOT_WIDTH;
    robot->height = ROBOT_HEIGHT;
    robot->direction = 0;
    robot->angle = 90;
    robot->currentSpeed = 0;
    robot->crashed = 0;
    robot->auto_mode = 0;
**/

    printf("Press arrow keys to move manually, or enter to move automatically\n\n");
}
int robot_off_screen(struct Robot *robot)
{
    if (robot->x < 0 || robot->y < 0)
    {
        return 0;
    }
    if (robot->x > OVERALL_WINDOW_WIDTH || robot->y > OVERALL_WINDOW_HEIGHT)
    {
        return 0;
    }
    return 1;
}

int checkRobotHitWall(struct Robot *robot, struct Wall *wall)
{

    int overlap = checkOverlap(robot->x, robot->width, robot->y, robot->height,
                               wall->x, wall->width, wall->y, wall->height);

    return overlap;
}

int checkRobotHitWalls(struct Robot *robot, struct Wall_collection *head)
{
    struct Wall_collection *ptr = head;
    int hit = 0;

    while (ptr != NULL)
    {
        hit = (hit || checkRobotHitWall(robot, &ptr->wall));
        ptr = ptr->next;
    }
    return hit;
}

int checkRobotReachedEnd(struct Robot *robot, int x, int y, int width, int height)
{

    int overlap = checkOverlap(robot->x, robot->width, robot->y, robot->height,
                               x, width, y, height);

    return overlap;
}

void robotCrash(struct Robot *robot)
{
    robot->currentSpeed = 0;
    if (!robot->crashed)
        printf("Ouchies!!!!!\n\nPress space to start again\n");
    robot->crashed = 1;
}

void robotSuccess(struct Robot *robot, int msec)
{
    robot->currentSpeed = 0;
    if (!robot->crashed)
    {
        printf("Success!!!!!\n\n");
        printf("Time taken %d seconds %d milliseconds \n", msec / 1000, msec % 1000);
        printf("Press space to start again\n");
    }
    robot->crashed = 1;
}

int checkRobotSensor(int x, int y, int sensorSensitivityLength, struct Wall *wall)
{
    //viewing_region of sensor is a square of 2 pixels * chosen length of sensitivity
    int overlap = checkOverlap(x, 2, y, sensorSensitivityLength,
                               wall->x, wall->width, wall->y, wall->height);

    return overlap;
}

int checkRobotSensorSideFrontAllWalls(struct Robot *robot, struct Wall_collection *head)
{
    struct Wall_collection *ptr, *head_store;
    int i;
    double xDir, yDir;
    int robotCentreX, robotCentreY, xTL, yTL;
    int score, hit;

    int sensorSensitivityLength = floor(SENSOR_VISION / 5);

    head_store = head;
    robotCentreX = robot->x + ROBOT_WIDTH / 2;
    robotCentreY = robot->y + ROBOT_HEIGHT / 2;
    score = 0;

    for (i = 0; i < 5; i++)
    {
        ptr = head_store;
        xDir = round(robotCentreX + (ROBOT_WIDTH / 2 - 2) * cos((robot->angle - 90) * PI / 180) - (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensorSensitivityLength * i) * sin((robot->angle + 90) * PI / 180));
        yDir = round(robotCentreY + (ROBOT_WIDTH / 2 - 2) * sin((robot->angle - 90) * PI / 180) + (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensorSensitivityLength * i) * cos((robot->angle + 90) * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;
        hit = 0;

        while (ptr != NULL)
        {
            hit = (hit || checkRobotSensor(xTL, yTL, sensorSensitivityLength, &ptr->wall));
            ptr = ptr->next;
        }
        if (hit)
            score = i;
    }
    return score;
}

int checkRobotSensorSideMiddleAllWalls(struct Robot *robot, struct Wall_collection *head)
{
    struct Wall_collection *ptr, *head_store;
    int i;
    double xDir, yDir;
    int robotCentreX, robotCentreY, xTL, yTL;
    int score, hit;

    int sensorSensitivityLength = floor(SENSOR_VISION / 5);

    head_store = head;
    robotCentreX = robot->x + ROBOT_WIDTH / 2;
    robotCentreY = robot->y + ROBOT_HEIGHT / 2;
    score = 0;

    for (i = 0; i < 5; i++)
    {
        ptr = head_store;
        xDir = round(robotCentreX + (ROBOT_WIDTH / 2 - 12) * cos((robot->angle - 90) * PI / 180) - (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensorSensitivityLength * i) * sin((robot->angle + 90) * PI / 180));
        yDir = round(robotCentreY + (ROBOT_WIDTH / 2 - 12) * sin((robot->angle - 90) * PI / 180) + (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensorSensitivityLength * i) * cos((robot->angle + 90) * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;
        hit = 0;

        while (ptr != NULL)
        {
            hit = (hit || checkRobotSensor(xTL, yTL, sensorSensitivityLength, &ptr->wall));
            ptr = ptr->next;
        }
        if (hit)
            score = i;
    }
    return score;
}

int checkRobotSensorFrontRightAllWalls(struct Robot *robot, struct Wall_collection *head)
{
    struct Wall_collection *ptr, *head_store;
    int i;
    double xDir, yDir;
    int robotCentreX, robotCentreY, xTL, yTL;
    int score, hit;
    int sensorSensitivityLength;

    head_store = head;
    robotCentreX = robot->x + ROBOT_WIDTH / 2;
    robotCentreY = robot->y + ROBOT_HEIGHT / 2;
    score = 0;
    sensorSensitivityLength = floor(SENSOR_VISION / 5);

    for (i = 0; i < 5; i++)
    {
        ptr = head_store;
        xDir = round(robotCentreX + (ROBOT_WIDTH / 2 - 2) * cos((robot->angle) * PI / 180) - (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensorSensitivityLength * i) * sin((robot->angle) * PI / 180));
        yDir = round(robotCentreY + (ROBOT_WIDTH / 2 - 2) * sin((robot->angle) * PI / 180) + (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensorSensitivityLength * i) * cos((robot->angle) * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;
        hit = 0;

        while (ptr != NULL)
        {
            hit = (hit || checkRobotSensor(xTL, yTL, sensorSensitivityLength, &ptr->wall));
            ptr = ptr->next;
        }
        if (hit)
            score = i;
    }
    return score;
}

void robotUpdate(struct SDL_Renderer *renderer, struct Robot *robot)
{
    double xDir, yDir;

    int robotCentreX, robotCentreY, xTR, yTR, xTL, yTL, xBR, yBR, xBL, yBL;
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);

    /*
    //Other Display options:
    // The actual square which the robot is tested against (not so nice visually with turns, but easier
    // to test overlap
    SDL_Rect rect = {robot->x, robot->y, robot->height, robot->width};
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);
    */
    /*
    //Center Line of Robot. Line shows the direction robot is facing
    xDir = -30 * sin(-robot->angle*PI/180);
    yDir = -30 * cos(-robot->angle*PI/180);
    xDirInt = robot->x+ROBOT_WIDTH/2+ (int) xDir;
    yDirInt = robot->y+ROBOT_HEIGHT/2+ (int) yDir;
    SDL_RenderDrawLine(renderer,robot->x+ROBOT_WIDTH/2, robot->y+ROBOT_HEIGHT/2, xDirInt, yDirInt);
    */

    //Rotating Square
    //Vector rotation to work out corners x2 = x1cos(angle)-y1sin(angle), y2 = x1sin(angle)+y1cos(angle)
    robotCentreX = robot->x + ROBOT_WIDTH / 2;
    robotCentreY = robot->y + ROBOT_HEIGHT / 2;

    xDir = round(robotCentreX + (ROBOT_WIDTH / 2) * cos((robot->angle) * PI / 180) - (-ROBOT_HEIGHT / 2) * sin((robot->angle) * PI / 180));
    yDir = round(robotCentreY + (ROBOT_WIDTH / 2) * sin((robot->angle) * PI / 180) + (-ROBOT_HEIGHT / 2) * cos((robot->angle) * PI / 180));
    xTR = (int)xDir;
    yTR = (int)yDir;

    xDir = round(robotCentreX + (ROBOT_WIDTH / 2) * cos((robot->angle) * PI / 180) - (ROBOT_HEIGHT / 2) * sin((robot->angle) * PI / 180));
    yDir = round(robotCentreY + (ROBOT_WIDTH / 2) * sin((robot->angle) * PI / 180) + (ROBOT_HEIGHT / 2) * cos((robot->angle) * PI / 180));
    xBR = (int)xDir;
    yBR = (int)yDir;

    xDir = round(robotCentreX + (-ROBOT_WIDTH / 2) * cos((robot->angle) * PI / 180) - (ROBOT_HEIGHT / 2) * sin((robot->angle) * PI / 180));
    yDir = round(robotCentreY + (-ROBOT_WIDTH / 2) * sin((robot->angle) * PI / 180) + (ROBOT_HEIGHT / 2) * cos((robot->angle) * PI / 180));
    xBL = (int)xDir;
    yBL = (int)yDir;

    xDir = round(robotCentreX + (-ROBOT_WIDTH / 2) * cos((robot->angle) * PI / 180) - (-ROBOT_HEIGHT / 2) * sin((robot->angle) * PI / 180));
    yDir = round(robotCentreY + (-ROBOT_WIDTH / 2) * sin((robot->angle) * PI / 180) + (-ROBOT_HEIGHT / 2) * cos((robot->angle) * PI / 180));
    xTL = (int)xDir;
    yTL = (int)yDir;

    SDL_RenderDrawLine(renderer, xTR, yTR, xBR, yBR);
    SDL_RenderDrawLine(renderer, xBR, yBR, xBL, yBL);
    SDL_RenderDrawLine(renderer, xBL, yBL, xTL, yTL);
    SDL_RenderDrawLine(renderer, xTL, yTL, xTR, yTR);

    //Side Front Sensor
    int sensor_sensitivity = floor(SENSOR_VISION / 5);
    int i;
    for (i = 0; i < 5; i++)
    {
        xDir = round(robotCentreX + (ROBOT_WIDTH / 2 - 2) * cos((robot->angle - 90) * PI / 180) - (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensor_sensitivity * i) * sin((robot->angle + 90) * PI / 180));
        yDir = round(robotCentreY + (ROBOT_WIDTH / 2 - 2) * sin((robot->angle - 90) * PI / 180) + (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensor_sensitivity * i) * cos((robot->angle + 90) * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;

        SDL_Rect rect = {xTL, yTL, 2, sensor_sensitivity};
        SDL_SetRenderDrawColor(renderer, 80 + (20 * (5 - i)), 80 + (20 * (5 - i)), 80 + (20 * (5 - i)), 255);
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }

    //Side Middle Sensor
    for (i = 0; i < 5; i++)
    {
        xDir = round(robotCentreX + (ROBOT_WIDTH / 2 - 12) * cos((robot->angle - 90) * PI / 180) - (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensor_sensitivity * i) * sin((robot->angle + 90) * PI / 180));
        yDir = round(robotCentreY + (ROBOT_WIDTH / 2 - 12) * sin((robot->angle - 90) * PI / 180) + (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensor_sensitivity * i) * cos((robot->angle + 90) * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;

        SDL_Rect rect = {xTL, yTL, 2, sensor_sensitivity};
        SDL_SetRenderDrawColor(renderer, 80 + (20 * (5 - i)), 80 + (20 * (5 - i)), 80 + (20 * (5 - i)), 255);
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }

    //Front Right Sensor
    for (i = 0; i < 5; i++)
    {
        xDir = round(robotCentreX + (ROBOT_WIDTH / 2 - 2) * cos((robot->angle) * PI / 180) - (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensor_sensitivity * i) * sin((robot->angle) * PI / 180));
        yDir = round(robotCentreY + (ROBOT_WIDTH / 2 - 2) * sin((robot->angle) * PI / 180) + (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensor_sensitivity * i) * cos((robot->angle) * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;

        SDL_Rect rect = {xTL, yTL, 2, sensor_sensitivity};
        SDL_SetRenderDrawColor(renderer, 80 + (20 * (5 - i)), 80 + (20 * (5 - i)), 80 + (20 * (5 - i)), 255);
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }

    //Front Left Sensor
    for (i = 0; i < 5; i++)
    {
        xDir = round(robotCentreX + (-ROBOT_WIDTH / 2) * cos((robot->angle) * PI / 180) - (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensor_sensitivity * i) * sin((robot->angle) * PI / 180));
        yDir = round(robotCentreY + (-ROBOT_WIDTH / 2) * sin((robot->angle) * PI / 180) + (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensor_sensitivity * i) * cos((robot->angle) * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;

        SDL_Rect rect = {xTL, yTL, 2, sensor_sensitivity};
        SDL_SetRenderDrawColor(renderer, 80 + (20 * (5 - i)), 80 + (20 * (5 - i)), 80 + (20 * (5 - i)), 255);
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
}

int checkRobotSensorFrontLeftAllWalls(struct Robot *robot, struct Wall_collection *head)
{
    struct Wall_collection *ptr, *head_store;
    int i;
    double xDir, yDir;
    int robotCentreX, robotCentreY, xTL, yTL;
    int score, hit;
    int sensorSensitivityLength;

    head_store = head;
    robotCentreX = robot->x + ROBOT_WIDTH / 2;
    robotCentreY = robot->y + ROBOT_HEIGHT / 2;
    score = 0;
    sensorSensitivityLength = floor(SENSOR_VISION / 5);

    for (i = 0; i < 5; i++)
    {
        ptr = head_store;
        xDir = round(robotCentreX + (-ROBOT_WIDTH / 2) * cos((robot->angle) * PI / 180) - (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensorSensitivityLength * i) * sin((robot->angle) * PI / 180));
        yDir = round(robotCentreY + (-ROBOT_WIDTH / 2) * sin((robot->angle) * PI / 180) + (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensorSensitivityLength * i) * cos((robot->angle) * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;
        hit = 0;

        while (ptr != NULL)
        {
            hit = (hit || checkRobotSensor(xTL, yTL, sensorSensitivityLength, &ptr->wall));
            ptr = ptr->next;
        }
        if (hit)
            score = i;
    }
    return score;
}

void robotMotorMove(struct Robot *robot)
{
    double x_offset, y_offset;
    switch (robot->direction)
    {
    case UP:
        robot->currentSpeed += DEFAULT_SPEED_CHANGE;
        if (robot->currentSpeed > MAX_ROBOT_SPEED)
            robot->currentSpeed = MAX_ROBOT_SPEED;
        break;
    case DOWN:
        robot->currentSpeed -= DEFAULT_SPEED_CHANGE;
        if (robot->currentSpeed < -MAX_ROBOT_SPEED)
            robot->currentSpeed = -MAX_ROBOT_SPEED;
        break;
    case LEFT:
        robot->angle = (robot->angle + 360 - DEFAULT_ANGLE_CHANGE) % 360;
        break;
    case RIGHT:
        robot->angle = (robot->angle + DEFAULT_ANGLE_CHANGE) % 360;
        break;
    }
    robot->direction = 0;
    x_offset = (-robot->currentSpeed * sin(-robot->angle * PI / 180));
    y_offset = (-robot->currentSpeed * cos(-robot->angle * PI / 180));

    robot->true_x += x_offset;
    robot->true_y += y_offset;

    x_offset = round(robot->true_x);
    y_offset = round(robot->true_y);

    robot->x = (int)x_offset;
    robot->y = (int)y_offset;
}

int robotAutoMotorMove(struct Robot *robot, int front_left, int front_right, int side_front, int side_middle, int found_wall, int *angle_changed_ptr, int *calibrated_ptr)
{

    int max_speed = 5;
    int is_speed_changed = 0;
    int is_calibrated = *calibrated_ptr;

    int front_right_max_threshold = 2;
    int front_left_max_threshold = 3;

    int side_min_threshold = 3;
    int side_max_threshold = 3;

    bool side_activated = side_front >= side_min_threshold;
    bool right_too_close = front_right > front_right_max_threshold;
    bool left_too_close = front_left >= front_left_max_threshold;
    bool sideTooClose = side_front > side_max_threshold;
    bool sideMiddleActivated = side_middle >= side_min_threshold;
    bool sideMiddleTooClose = side_middle > side_max_threshold;

    if (robot->crashed)
    {
        robot->currentSpeed = 0;
        return 0;
    }

    //robot->currentSpeed = 0;
    printf("Speed: ");
    printf("%d\n", robot->currentSpeed);
    printf("Is calibrated: %d\n", is_calibrated);

    if (found_wall == 0)
    {
        //Wall has not been found;
        // Move forward and to right
        // if (robot->currentSpeed >= 0 && robot->currentSpeed <= 2)
        // {
        //     robot->direction = UP;
        // }
        // else
        // {
        //     if (*angle_changed_ptr <= 3)
        //     {
        //         robot->direction = RIGHT;
        //         *angle_changed_ptr += 1;
        //     }
        // }

        if (*angle_changed_ptr < 90)
        {
            robot->direction = RIGHT;
            *angle_changed_ptr += DEFAULT_ANGLE_CHANGE;
        }
        else
        {
            if (robot->currentSpeed == 0)
            {
                robot->direction = UP;
            }
        }

        //If the wall is found
        if (front_left > 2 || front_right > 2 || side_front > 2 || side_middle > 2)
        {
            printf("Wall Found\n");
            // robot->direction = LEFT;
            return 1;
        }
        return 0;
    }
    else if (!is_calibrated)
    {
        if (robot->currentSpeed > 1)
        {

            robot->direction = DOWN;
            return 1;
        }

        // if (side_middle == 0 || side_front == 0)
        // {
        //     printf("Turning left on line 452\n");
        //     robot->direction = LEFT;
        //     return 1;
        // }

        if (*angle_changed_ptr > 0)
        {
            robot->direction = LEFT;
            *angle_changed_ptr -= DEFAULT_ANGLE_CHANGE;
            return 1;
        }

        *calibrated_ptr = 1;
        return 1;
    }
    else
    {
        //Are the sides Activated
        if (!side_activated)
        {
            //If the middle is not too close, turn right
            if (!sideMiddleTooClose)
            {
                printf("Turning right #1\n");
                robot->direction = RIGHT;
            }
            else
            {
                if (robot->currentSpeed > 1)
                {
                    printf("Slowing down #1\n");
                    robot->direction = DOWN;
                    is_speed_changed = 1;
                }
            }
        }
        else
        {
            if (front_left > 0 || front_right > 1)
            {
                if (robot->currentSpeed > 1)
                {
                    printf("Slowing down #2\n");
                    robot->direction = DOWN;
                    is_speed_changed = 1;
                }
            }
            else
            {
                if (robot->currentSpeed < max_speed)
                {
                    printf("Speeding up #1\n");
                    robot->direction = UP;
                    is_speed_changed = 1;
                }
            }
        }

        if ((right_too_close || sideTooClose || sideMiddleTooClose) && !is_speed_changed)
        {
            printf("Turning left #1\n");
            robot->direction = LEFT;
        }

        printf("final direction: %d\n", robot->direction);

        return 1;
    }
}
