
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 7; }

// ��������Ʒ���
int get_fin_type() { return 2269; }

// ���������촦��
void create()
{
        set_name("��񷷨��");
        set_picid_1(6162);
        set_picid_2(6162);

        set_level(115);
        set_value(11500);
        set_max_lasting(27899);
        set("ap", 0);
        set("dp", 186);
        set("cp", 0);
        set("pp", 302);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��񷷨��";
}
