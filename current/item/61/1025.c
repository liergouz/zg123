
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("����ȹ");
        set_picid_1(6174);
        set_picid_2(6174);

        set_level(25);
        set_value(3000);
        set_max_lasting(9099);
        set("dp", 66);
        set("pp", 39);

        setup();

        set_gender(2);
        set_armor_code(21);
}

// ��������ȡ����
string get_desc()
{
        return "����ȹ";
}
