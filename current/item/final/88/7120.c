
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 7; }

// ��������Ʒ���
int get_fin_type() { return 2300; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(120);
        set_value(12000);
        set_max_lasting(28899);
        set("ap", 0);
        set("dp", 56);
        set("cp", 0);
        set("pp", 0);
        set("sp", 60);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
