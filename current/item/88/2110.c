
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(110);
        set_value(27700);
        set_max_lasting(12699);
        set("dp", 52);
        set("sp", 64);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
