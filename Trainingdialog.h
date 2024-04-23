#ifndef TRAININGDIALOG_H
#define TRAININGDIALOG_H

#include <QDialog>
#include <string>

namespace Ui {
class TrainingDialog;
}

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April 22, 2024
 * @name TrainingDialog header file for assignment9
 * This header file defines the TrainingDialog class, which is used to display educational material
 * about logic gates in a dialog format, including images and truth tables.
 */

class TrainingDialog : public QDialog
{
    Q_OBJECT

public:
    /// @brief Constructor for TrainingDialog.
    explicit TrainingDialog(QWidget *parent = nullptr);

    /// @brief Destructor for TrainingDialog.
    ~TrainingDialog();

    /// @brief Sets up the dialog with an image and descriptive text for the logic gate.
    void setupImageAndText(const QString &imagePath, const QString &text);

    /// @brief Configures the dialog to display the truth table for a specific logic gate.
    void setTruthTable(std::string gate);

private:
    Ui::TrainingDialog *ui; ///< Pointer to the user interface setup for the dialog.
};

#endif // TRAININGDIALOG_H
