
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("ˮ��ȹ");
        set_picid_1(6134);
        set_picid_2(6134);

        set_level(35);
        set_value(9000);
        set_max_lasting(10899);
        set("dp", 76);
        set("pp", 46);

        setup();

        set_gender(2);
        set_armor_code(22);
}

// ��������ȡ����
string get_desc()
{
        return "ˮ��ȹ";
}
