
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("��˪��");
        set_picid_1(6056);
        set_picid_2(6056);

        set_level(40);
        set_value(14500);
        set_max_lasting(7299);
        set("dp", 64);
        set("pp", 106);

        setup();

        set_gender(1);
        set_armor_code(3);
}

// ��������ȡ����
string get_desc()
{
        return "��˪��";
}
