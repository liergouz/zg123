
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("����ս��");
        set_picid_1(6162);
        set_picid_2(6162);

        set_level(110);
        set_value(70500);
        set_max_lasting(15699);
        set("dp", 148);
        set("pp", 274);

        setup();

        set_gender(2);
        set_armor_code(28);
}

// ��������ȡ����
string get_desc()
{
        return "����ս��";
}
