
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 5; }

// ��������Ʒ���
int get_fin_type() { return 2043; }

// ���������촦��
void create()
{
        set_name("ն��Ь");
        set_picid_1(8813);
        set_picid_2(8813);

        set_level(80);
        set_value(6500);
        set_max_lasting(16899);
        set("ap", 0);
        set("dp", 35);
        set("cp", 0);
        set("pp", 0);
        set("sp", 40);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ն��Ь";
}
