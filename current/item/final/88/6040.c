
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 1259; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8804);
        set_picid_2(8804);

        set_level(40);
        set_value(4000);
        set_max_lasting(9899);
        set("ap", 0);
        set("dp", 15);
        set("cp", 0);
        set("pp", 0);
        set("sp", 20);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
