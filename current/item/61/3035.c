
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("����ȹ");
        set_picid_1(6134);
        set_picid_2(6134);

        set_level(35);
        set_value(8500);
        set_max_lasting(12099);
        set("dp", 93);
        set("pp", 51);

        setup();

        set_gender(2);
        set_armor_code(22);
}

// ��������ȡ����
string get_desc()
{
        return "����ȹ";
}
