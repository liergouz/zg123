
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("˿����");
        set_picid_1(6076);
        set_picid_2(6076);

        set_level(30);
        set_value(5000);
        set_max_lasting(10599);
        set("dp", 77);
        set("pp", 46);

        setup();

        set_gender(1);
        set_armor_code(2);
}

// ��������ȡ����
string get_desc()
{
        return "˿����";
}
