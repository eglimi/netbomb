#ifndef SPIELOPIVIEW_H
#define SPIELOPIVIEW_H
#include "generated/gspieloptionen.h"

class SpielView;

class SpielOpiView : public ggameoptions
{ 
    Q_OBJECT

public:
    SpielOpiView( SpielView* spielview,
                  QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~SpielOpiView();

public slots:
    void bApplyPressed();
    void bCancelPressed();

private:
    SpielView* _spielview;

};

#endif // SPIELOPIVIEW_H
