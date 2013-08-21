#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QComboBox>

class QLabel;

class ComboBox : public QComboBox {
    Q_OBJECT

  public:
    // Constructors and destructors
    ComboBox(QWidget *parent = 0);
    ~ComboBox();

  protected:
    // Places clear button into the correct position.
    void resizeEvent(QResizeEvent *event);

    // Returns width of QLineEdit frame.
    int frameWidth() const;

  private:
    QLabel *m_label;
};

#endif // COMBOBOX_H
