#include "drawingcanvas.h"

DrawingCanvas::DrawingCanvas(QWidget *parent)  {
    // Set a minimum size for the canvas
    setMinimumSize(this->WINDOW_WIDTH, this->WINDOW_HEIGHT);
    setMaximumSize(this->WINDOW_WIDTH, this->WINDOW_HEIGHT);
    // Set a solid background color
    setStyleSheet("background-color: white; border: 1px solid gray;");
}

void DrawingCanvas::clearPoints(){
    m_points.clear();
    // Trigger a repaint to clear the canvas
    update();
}

void DrawingCanvas::paintLines(){
    /* Todo
     * Implement lines drawing per even pair
    */

    isPaintLinesClicked = true;
    update();
}

void DrawingCanvas::segmentDetection(){
    QPixmap pixmap = this->grab(); //
    QImage image = pixmap.toImage();

    cout << "image width" << image.width() << endl;
    cout << "image height" << image.height() << endl;


    // CustomMatrix mat;
    // mat.fillMatrix(x);
    // vector<CustomMatrix> windows;
    // //windows.push_back(mat);

    // // Get the pixel value as an ARGB integer (QRgb is a typedef for unsigned int)
    // for(int i = 1; i < image.width()-1;i++){
    //     for(int j = 1; j < image.height()-1;j++){
    //         QRgb rgbValue = image.pixel(i, j);
    //         bool x[3][3] = {false};
    //         for(int m = -1; m <= 1; m++) {
    //             for(int n = -1; n <= 1; n++){
    //                 QRgb neighborRgbValue = image.pixel(i + m, j + n);
    //                 x[m + 1][n + 1] = (neighborRgbValue != 0xffffffff);
    //             }
    //         }
    //         CustomMatrix mat;
    //         mat.fillMatrix(x);
    //         windows.push_back(mat);
    //         cout << "(" << i << "," << j << "): " << hex << showbase << rgbValue << endl;
    //         //cout << "isWhite " << (rgbValue == 0xffffffff) << endl;
    //     }
    // }
    vector<std::array<std::array<bool,3>,3>> possibilities;
    //+
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,1,0},std::array<bool,3>{1,1,1},std::array<bool,3>{0,1,0}});

    //T
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,1},std::array<bool,3>{0,1,0},std::array<bool,3>{0,1,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,1},std::array<bool,3>{0,1,0},std::array<bool,3>{0,0,0}});


    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,1,0},std::array<bool,3>{0,1,0},std::array<bool,3>{1,1,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{0,1,0},std::array<bool,3>{1,1,1}});


    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,0,0},std::array<bool,3>{1,1,1},std::array<bool,3>{1,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,0,0},std::array<bool,3>{1,1,0},std::array<bool,3>{1,0,0}});


    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,1},std::array<bool,3>{1,1,1},std::array<bool,3>{0,0,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,1},std::array<bool,3>{0,1,1},std::array<bool,3>{0,0,1}});

    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,1,0},std::array<bool,3>{1,1,1},std::array<bool,3>{0,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{1,1,1},std::array<bool,3>{0,1,0}});


    //L
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,1},std::array<bool,3>{1,0,0},std::array<bool,3>{1,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,0},std::array<bool,3>{1,0,0},std::array<bool,3>{1,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,1},std::array<bool,3>{1,0,0},std::array<bool,3>{0,0,0}});

    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,0,0},std::array<bool,3>{1,0,0},std::array<bool,3>{1,1,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,0,0},std::array<bool,3>{1,0,0},std::array<bool,3>{1,1,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{1,0,0},std::array<bool,3>{1,1,1}});

    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,0,0},std::array<bool,3>{1,1,1},std::array<bool,3>{0,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,0,0},std::array<bool,3>{1,1,0},std::array<bool,3>{0,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{1,1,1},std::array<bool,3>{1,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{1,1,0},std::array<bool,3>{1,0,0}});

    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{1,1,1},std::array<bool,3>{0,0,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{0,1,1},std::array<bool,3>{0,0,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,1},std::array<bool,3>{1,1,1},std::array<bool,3>{0,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,1},std::array<bool,3>{0,1,1},std::array<bool,3>{0,0,0}});

    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,1},std::array<bool,3>{0,0,1},std::array<bool,3>{1,1,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,1},std::array<bool,3>{0,0,1},std::array<bool,3>{0,1,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{0,0,1},std::array<bool,3>{1,1,1}});

    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,1},std::array<bool,3>{0,0,1},std::array<bool,3>{0,0,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,1},std::array<bool,3>{0,0,1},std::array<bool,3>{0,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,1,1},std::array<bool,3>{0,0,1},std::array<bool,3>{0,0,1}});

    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,1},std::array<bool,3>{1,0,0},std::array<bool,3>{1,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,1},std::array<bool,3>{1,0,0},std::array<bool,3>{0,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,0},std::array<bool,3>{1,0,0},std::array<bool,3>{1,0,0}});

    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,0},std::array<bool,3>{0,1,0},std::array<bool,3>{0,1,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,1,1},std::array<bool,3>{0,1,0},std::array<bool,3>{0,1,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,0},std::array<bool,3>{0,1,0},std::array<bool,3>{0,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,1,1},std::array<bool,3>{0,1,0},std::array<bool,3>{0,0,0}});

    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,1,0},std::array<bool,3>{0,1,0},std::array<bool,3>{0,1,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,1,0},std::array<bool,3>{0,1,0},std::array<bool,3>{1,1,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{0,1,0},std::array<bool,3>{0,1,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{0,1,0},std::array<bool,3>{1,1,0}});


    //X
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,0,1},std::array<bool,3>{0,1,0},std::array<bool,3>{1,0,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,1},std::array<bool,3>{0,1,0},std::array<bool,3>{1,0,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,0,1},std::array<bool,3>{0,1,0},std::array<bool,3>{1,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,0,0},std::array<bool,3>{0,1,0},std::array<bool,3>{1,0,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,0,1},std::array<bool,3>{0,1,0},std::array<bool,3>{0,0,1}});

    //7
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,1},std::array<bool,3>{0,1,0},std::array<bool,3>{1,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,1},std::array<bool,3>{0,1,0},std::array<bool,3>{0,0,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,1,1},std::array<bool,3>{0,1,0},std::array<bool,3>{1,0,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,1,0},std::array<bool,3>{0,1,0},std::array<bool,3>{0,0,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,0,0},std::array<bool,3>{0,1,0},std::array<bool,3>{1,1,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,1},std::array<bool,3>{0,1,0},std::array<bool,3>{1,1,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{0,1,0},std::array<bool,3>{1,1,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{0,1,0},std::array<bool,3>{1,1,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{1,0,0},std::array<bool,3>{0,1,0},std::array<bool,3>{0,1,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,1},std::array<bool,3>{0,1,0},std::array<bool,3>{1,1,0}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{0,1,0},std::array<bool,3>{0,1,1}});
    possibilities.push_back(std::array<std::array<bool,3>,3>{std::array<bool,3>{0,0,0},std::array<bool,3>{0,1,0},std::array<bool,3>{1,1,0}});

    vector<CustomMatrix> windows(image.width()*image.height());

    // Get the pixel value as an ARGB integer (QRgb is a typedef for unsigned int)
    for(int i = 1; i < image.width()-4;i+=3){
        for(int j = 1; j < image.height()-4;j+=3){
            std::array<std::array<bool,3>,3> local_window = {std::array<bool,3>{false,false,false},std::array<bool,3>{false,false,false},std::array<bool,3>{false,false,false}};

            for(int m=-1;m<=1;m++){
                for(int n=-1;n<=1;n++){
                    QRgb rgbValue = image.pixel(i+m, j+n);
                    local_window[m+1][n+1] = (rgbValue != 0xffffffff);
                }
            }

            CustomMatrix mat(local_window);

            windows[i] = mat;

            // for(int o=0;i<possibilities.size();o++){
            //     for(int p=0;j<2;p++){
            //     }
            // }
        }
    }

    cout << (windows[1].mat[0] == windows[1].mat[1]);

    //possibilities check



    // vector<CustomMatrix> possibilities;
    // possibilities.push_back({{}});

}

void DrawingCanvas::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Set up the pen and brush for drawing the points
    QPen pen(Qt::blue, 5);
    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::blue));

    // Draw a small circle at each stored point
    for (const QPoint& point : std::as_const(m_points)) {
        painter.drawEllipse(point, 3, 3);
    }

    if(isPaintLinesClicked){
        cout << "paint lines block is called" << endl;
        pen.setColor(Qt::red);
        pen.setWidth(1); // 4-pixel wide line
        pen.setStyle(Qt::SolidLine);
        painter.setPen(pen);

        // Set the painter's pen to our custom pen.
        painter.setPen(pen);

        for(int i=0;i<m_points.size()-1;i+=2){
            //cout << m_points[i].x() << endl;
            painter.drawLine(m_points[i], m_points[i+1]);
        }
        isPaintLinesClicked = false;

        //return painter pen to blue
        pen.setColor(Qt::blue);
        painter.setPen(pen);
    }
}

void DrawingCanvas::mousePressEvent(QMouseEvent *event) {
    // Add the mouse click position to our vector of points
    m_points.append(event->pos());
    // Trigger a repaint
    update();
}


