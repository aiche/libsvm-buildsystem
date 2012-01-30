
#include "svm-toy.moc"

SvmToyWindow::SvmToyWindow()
:button_change_icon(this)
,button_run("Run",this)
,button_clear("Clear",this)
,button_save("Save",this)
,button_load("Load",this)
,input_line(this)
,current_value(1)
{
	buffer = QPixmap(XLEN,YLEN);
	buffer.fill(Qt::black);

	buffer_painter.begin(&buffer);

	QObject::connect(&button_change_icon, SIGNAL(clicked()), this,
			 SLOT(button_change_icon_clicked()));
	QObject::connect(&button_run, SIGNAL(clicked()), this,
			 SLOT(button_run_clicked()));
	QObject::connect(&button_clear, SIGNAL(clicked()), this,
			 SLOT(button_clear_clicked()));
	QObject::connect(&button_save, SIGNAL(clicked()), this,
			 SLOT(button_save_clicked()));
	QObject::connect(&button_load, SIGNAL(clicked()), this,
			 SLOT(button_load_clicked()));
	QObject::connect(&input_line, SIGNAL(returnPressed()), this,
			 SLOT(button_run_clicked()));

  	// don't blank the window before repainting
	setAttribute(Qt::WA_NoBackground);
  
	icon1 = QPixmap(4,4);
	icon2 = QPixmap(4,4);
	icon3 = QPixmap(4,4);
	
	
	QPainter painter;
	painter.begin(&icon1);
	painter.fillRect(0,0,4,4,QBrush(colors[4]));
	painter.end();

	painter.begin(&icon2);
	painter.fillRect(0,0,4,4,QBrush(colors[5]));
	painter.end();

	painter.begin(&icon3);
	painter.fillRect(0,0,4,4,QBrush(colors[6]));
	painter.end();

	button_change_icon.setGeometry( 0, YLEN, 50, 25 );
	button_run.setGeometry( 50, YLEN, 50, 25 );
	button_clear.setGeometry( 100, YLEN, 50, 25 );
	button_save.setGeometry( 150, YLEN, 50, 25);
	button_load.setGeometry( 200, YLEN, 50, 25);
	input_line.setGeometry( 250, YLEN, 250, 25);
	
	input_line.setText(DEFAULT_PARAM);
	button_change_icon.setIcon(icon1);
}

SvmToyWindow::~SvmToyWindow()
{
	buffer_painter.end();
}

void SvmToyWindow::mousePressEvent( QMouseEvent* event )
{
	point p = {(double)event->x()/XLEN, (double)event->y()/YLEN, current_value};
	point_list.push_back(p);
	draw_point(p);
}

void SvmToyWindow::paintEvent( QPaintEvent* )
{
	// copy the image from the buffer pixmap to the window
	QPainter p(this);
	p.drawPixmap(0, 0, buffer);
}

int main( int argc, char* argv[] )
{
	QApplication myapp( argc, argv );

	SvmToyWindow* mywidget = new SvmToyWindow();
	mywidget->setGeometry( 100, 100, XLEN, YLEN+25 );

	mywidget->show();
	return myapp.exec();
}
