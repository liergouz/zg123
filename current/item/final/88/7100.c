
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 7; }

// ��������Ʒ���
int get_fin_type() { return 2082; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8811);
        set_picid_2(8811);

        set_level(100);
        set_value(7500);
        set_max_lasting(18899);
        set("ap", 0);
        set("dp", 46);
        set("cp", 0);
        set("pp", 0);
        set("sp", 50);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
