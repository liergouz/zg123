
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 5; }

// ��������Ʒ���
int get_fin_type() { return 2294; }

// ���������촦��
void create()
{
        set_name("����֮��");
        set_picid_1(6658);
        set_picid_2(6658);

        set_level(120);
        set_value(12000);
        set_max_lasting(28899);
        set("ap", 0);
        set("dp", 85);
        set("cp", 0);
        set("pp", 144);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����֮��";
}
