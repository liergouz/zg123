
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("����ͷ��");
        set_picid_1(6600);
        set_picid_2(6600);

        set_level(20);
        set_value(1600);
        set_max_lasting(5499);
        set("dp", 26);
        set("pp", 18);

        setup();

        set_gender(2);
        set_head_code(51);
}

// ��������ȡ����
string get_desc()
{
        return "����ͷ��";
}
