
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("����ͷ��");
        set_picid_1(6610);
        set_picid_2(6610);

        set_level(25);
        set_value(4300);
        set_max_lasting(5199);
        set("dp", 20);
        set("pp", 31);

        setup();

        set_gender(2);
        set_head_code(51);
}

// ��������ȡ����
string get_desc()
{
        return "����ͷ��";
}
