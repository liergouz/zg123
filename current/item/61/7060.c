
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("������ȹ");
        set_picid_1(6138);
        set_picid_2(6138);

        set_level(60);
        set_value(30500);
        set_max_lasting(9699);
        set("dp", 88);
        set("pp", 154);

        setup();

        set_gender(2);
        set_armor_code(24);
}

// ��������ȡ����
string get_desc()
{
        return "������ȹ";
}
