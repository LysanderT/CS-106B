#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    string pen = "up"; // records whether the pen is up or down.
    PenStyle style = {1, "black"}; // initialize the style of pen.
    double cx = 0, cy = 0; // records current position of the pen.
    double dx, dy, tx, ty;
    for (string line; getline(input, line);){
        Vector<string> commands = stringSplit(line," ");
        string command = toLowerCase(commands[0]);
        if (command == "pendown"){
            pen = "down";
            continue;
        }
        if (command == "penup"){
            pen = "up";
            continue;
        }
        if (command == "pencolor"){
            style.color = commands[1];
            continue;
        }
        if (command == "penwidth"){
            style.width = stringToReal(commands[1]);
            continue;
        }
        if (command == "moveabs"){
            tx = stringToReal(commands[1]);
            ty = stringToReal(commands[2]);
            if (pen == "down"){
                drawLine(cx,cy,tx,ty,style);
            }
            cx = tx;
            cy = ty;
            continue;
        }
        if (command == "moverel"){
            dx = stringToReal(commands[1]);
            dy = stringToReal(commands[2]);
            tx = cx + dx;
            ty = cy + dy;
            if (pen == "down"){
                drawLine(cx,cy,tx,ty,style); // wrong if use (cx+dx) instead of tx here.
            }
            cx = tx; // wrong if use (cx+dx) instead of tx here. But Idk why.
            cy = ty;
            continue;
        }
    }
}
