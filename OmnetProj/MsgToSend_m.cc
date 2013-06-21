//
// Generated file, do not edit! Created by opp_msgc 4.2 from MsgToSend.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MsgToSend_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(MsgToSend);

MsgToSend::MsgToSend(const char *name, int kind) : cPacket(name,kind)
{
    this->someField_var = 0;
    this->anotherField_var = 0;
    arrayField1_arraysize = 0;
    this->arrayField1_var = 0;
    for (unsigned int i=0; i<10; i++)
        this->arrayField2_var[i] = 0;
}

MsgToSend::MsgToSend(const MsgToSend& other) : cPacket(other)
{
    arrayField1_arraysize = 0;
    this->arrayField1_var = 0;
    copy(other);
}

MsgToSend::~MsgToSend()
{
    delete [] arrayField1_var;
}

MsgToSend& MsgToSend::operator=(const MsgToSend& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void MsgToSend::copy(const MsgToSend& other)
{
    this->someField_var = other.someField_var;
    this->anotherField_var = other.anotherField_var;
    delete [] this->arrayField1_var;
    this->arrayField1_var = (other.arrayField1_arraysize==0) ? NULL : new double[other.arrayField1_arraysize];
    arrayField1_arraysize = other.arrayField1_arraysize;
    for (unsigned int i=0; i<arrayField1_arraysize; i++)
        this->arrayField1_var[i] = other.arrayField1_var[i];
    for (unsigned int i=0; i<10; i++)
        this->arrayField2_var[i] = other.arrayField2_var[i];
}

void MsgToSend::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->someField_var);
    doPacking(b,this->anotherField_var);
    b->pack(arrayField1_arraysize);
    doPacking(b,this->arrayField1_var,arrayField1_arraysize);
    doPacking(b,this->arrayField2_var,10);
}

void MsgToSend::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->someField_var);
    doUnpacking(b,this->anotherField_var);
    delete [] this->arrayField1_var;
    b->unpack(arrayField1_arraysize);
    if (arrayField1_arraysize==0) {
        this->arrayField1_var = 0;
    } else {
        this->arrayField1_var = new double[arrayField1_arraysize];
        doUnpacking(b,this->arrayField1_var,arrayField1_arraysize);
    }
    doUnpacking(b,this->arrayField2_var,10);
}

int MsgToSend::getSomeField() const
{
    return someField_var;
}

void MsgToSend::setSomeField(int someField)
{
    this->someField_var = someField;
}

const char * MsgToSend::getAnotherField() const
{
    return anotherField_var.c_str();
}

void MsgToSend::setAnotherField(const char * anotherField)
{
    this->anotherField_var = anotherField;
}

void MsgToSend::setArrayField1ArraySize(unsigned int size)
{
    double *arrayField1_var2 = (size==0) ? NULL : new double[size];
    unsigned int sz = arrayField1_arraysize < size ? arrayField1_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        arrayField1_var2[i] = this->arrayField1_var[i];
    for (unsigned int i=sz; i<size; i++)
        arrayField1_var2[i] = 0;
    arrayField1_arraysize = size;
    delete [] this->arrayField1_var;
    this->arrayField1_var = arrayField1_var2;
}

unsigned int MsgToSend::getArrayField1ArraySize() const
{
    return arrayField1_arraysize;
}

double MsgToSend::getArrayField1(unsigned int k) const
{
    if (k>=arrayField1_arraysize) throw cRuntimeError("Array of size %d indexed by %d", arrayField1_arraysize, k);
    return arrayField1_var[k];
}

void MsgToSend::setArrayField1(unsigned int k, double arrayField1)
{
    if (k>=arrayField1_arraysize) throw cRuntimeError("Array of size %d indexed by %d", arrayField1_arraysize, k);
    this->arrayField1_var[k] = arrayField1;
}

unsigned int MsgToSend::getArrayField2ArraySize() const
{
    return 10;
}

double MsgToSend::getArrayField2(unsigned int k) const
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    return arrayField2_var[k];
}

void MsgToSend::setArrayField2(unsigned int k, double arrayField2)
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    this->arrayField2_var[k] = arrayField2;
}

class MsgToSendDescriptor : public cClassDescriptor
{
  public:
    MsgToSendDescriptor();
    virtual ~MsgToSendDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MsgToSendDescriptor);

MsgToSendDescriptor::MsgToSendDescriptor() : cClassDescriptor("MsgToSend", "cPacket")
{
}

MsgToSendDescriptor::~MsgToSendDescriptor()
{
}

bool MsgToSendDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MsgToSend *>(obj)!=NULL;
}

const char *MsgToSendDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MsgToSendDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int MsgToSendDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *MsgToSendDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "someField",
        "anotherField",
        "arrayField1",
        "arrayField2",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int MsgToSendDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "someField")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "anotherField")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrayField1")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrayField2")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MsgToSendDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
        "double",
        "double",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *MsgToSendDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MsgToSendDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MsgToSend *pp = (MsgToSend *)object; (void)pp;
    switch (field) {
        case 2: return pp->getArrayField1ArraySize();
        case 3: return 10;
        default: return 0;
    }
}

std::string MsgToSendDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MsgToSend *pp = (MsgToSend *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSomeField());
        case 1: return oppstring2string(pp->getAnotherField());
        case 2: return double2string(pp->getArrayField1(i));
        case 3: return double2string(pp->getArrayField2(i));
        default: return "";
    }
}

bool MsgToSendDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MsgToSend *pp = (MsgToSend *)object; (void)pp;
    switch (field) {
        case 0: pp->setSomeField(string2long(value)); return true;
        case 1: pp->setAnotherField((value)); return true;
        case 2: pp->setArrayField1(i,string2double(value)); return true;
        case 3: pp->setArrayField2(i,string2double(value)); return true;
        default: return false;
    }
}

const char *MsgToSendDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *MsgToSendDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MsgToSend *pp = (MsgToSend *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


