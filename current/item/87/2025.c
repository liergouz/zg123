
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8707);
        set_picid_2(8707);

        set_level(25);
        set_value(3750);
        set_max_lasting(7099);
        set("dp", 28);
        set("pp", 13);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
