#ifndef ADA95IMPORT_H
#define ADA95IMPORT_H

#include "codeimport/nativeimportbase.h"

/**
 * Ada95 code import using ANTLR visitor
 */
class Ada95Import : public NativeImportBase
{
public:
    explicit Ada95Import(CodeImpThread* thread = nullptr);
    virtual ~Ada95Import();

    bool parseFile(const QString& fileName);

protected:
    void fillSource(const QString& word) override {
        Q_UNUSED(word);
        // Not used; parsing is handled by ANTLR
    }

    bool parseStmt() override {
        // Not used; parsing is handled by ANTLR
        return false;
    }
};

#endif // ADA95IMPORT_H
