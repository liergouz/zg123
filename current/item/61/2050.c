
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��Х��ȹ");
        set_picid_1(6154);
        set_picid_2(6154);

        set_level(50);
        set_value(20500);
        set_max_lasting(16599);
        set("dp", 121);
        set("pp", 77);

        setup();

        set_gender(2);
        set_armor_code(23);
}

// ��������ȡ����
string get_desc()
{
        return "��Х��ȹ";
}
