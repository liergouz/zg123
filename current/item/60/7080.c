
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(6060);
        set_picid_2(6060);

        set_level(80);
        set_value(46500);
        set_max_lasting(12099);
        set("dp", 112);
        set("pp", 202);

        setup();

        set_gender(1);
        set_armor_code(6);
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
