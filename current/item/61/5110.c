
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("ն��ս��");
        set_picid_1(6162);
        set_picid_2(6162);

        set_level(110);
        set_value(70500);
        set_max_lasting(15699);
        set("dp", 145);
        set("pp", 271);

        setup();

        set_gender(2);
        set_armor_code(28);
}

// ��������ȡ����
string get_desc()
{
        return "ն��ս��";
}
