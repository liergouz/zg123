
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��Ես��");
        set_picid_1(6162);
        set_picid_2(6162);

        set_level(110);
        set_value(54000);
        set_max_lasting(39099);
        set("dp", 192);
        set("pp", 151);

        setup();

        set_gender(2);
        set_armor_code(28);
}

// ��������ȡ����
string get_desc()
{
        return "��Ես��";
}
